
//
// img.c
//
// Copyright (c) 2011 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Program version.
 */

#define VERSION "0.0.1"

/*
 * Sniff bytes for JPEG's magic number ff d8.
 */

int
is_jpeg(uint8_t *buf) {
  return 0xff == buf[0] && 0xd8 == buf[1];
}

/*
 * Sniff bytes 0..2 for "GIF".
 */

int
is_gif(uint8_t *buf) {
  return 'G' == buf[0] && 'I' == buf[1] && 'F' == buf[2];
}

/*
 * Sniff bytes 1..3 for "PNG".
 */

int
is_png(uint8_t *buf) {
  return 'P' == buf[1] && 'N' == buf[2] && 'G' == buf[3];
}

/*
 * Read big-endian uint32 from `buf`.
 */

int
read_uint32(char *buf) {
  return buf[0] << 24
      | buf[1] << 16
      | buf[2] << 8
      | buf[3] & 0xff;
}

/*
 * Read little-endian uint16 from `buf`.
 */

int
read_uint16(char *buf) {
  return buf[1] << 8
    | buf[0];
}

/*
 * Output CSS for `width` / `height`.
 */

void
output_css_dimensions(int width, int height) {
  printf("width: %dpx;\n", width);
  printf("height: %dpx;\n", height);
}

/*
 * Read `len` bytes at the given `offset` into `buf`.
 */

void
read_from(const char *path, char *buf, int len, int offset) {
  // open file
  int fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("open()");
    exit(1);
  }
 
  // read bytes
  if (pread(fd, buf, len, offset) < 0) {
    perror("read()");
    exit(1);
  }
  close(fd);
}

/*
 * Output GIF dimensions for `path`.
 */

void
output_gif_dimensions(const char *path) {
  char buf[4];
  read_from(path, buf, 4, 6);
  output_css_dimensions(
      read_uint16(buf)
    , read_uint16(buf + 2));
}

/*
 * Output PNG dimensions for `path`.
 */

void
output_png_dimensions(const char *path) {
  // read bytes
  char buf[8];
  read_from(path, buf, 8, 16);
  output_css_dimensions(
      read_uint32(buf)
    , read_uint32(buf + 4));
}

/*
 * Output JPEG dimensions for `path`.
 */

void
output_jpeg_dimensions(const char *path) {
  fprintf(stderr, "jpeg not yet supported\n");
  exit(1);
}

/*
 * Output usage information.
 */

void
usage() {
  printf(
    "\n"
    "  Usage: img <path>\n"
    "\n");
  exit(1);
}

/*
 * Handle args.
 */

int
main(int argc, const char **argv){
  // path required
  if (argc < 2) usage();

  const char *path = argv[1];

  // open file
  int fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("open()");
    exit(1);
  }

  // read bytes
  char buf[5];
  if (read(fd, &buf, 5) < 0) {
    perror("read()");
    exit(1);
  }
  close(fd);

  // sniff bytes
  if (is_gif(buf)) output_gif_dimensions(path);
  else if (is_png(buf)) output_png_dimensions(path);
  else if (is_jpeg(buf)) output_jpeg_dimensions(path);
  
  return 0;
}