
SRC = $(shell find src/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -std=c99
PREFIX = /usr/local

img: $(OBJ)
	$(CC) $^ -o $@

install: img
	cp -f $< $(PREFIX)/bin/$<

uninstall:
	rm -f $(PREFIX)/bin/img

test:
	@echo PNG
	@./img test/firefox.png
	@./img test/apple.png
	@echo
	@echo GIF
	@./img test/puffer.gif
	@./img test/google.gif
	@echo
	@echo JPEG
	@./img test/jpeg

clean:
	rm -f img

.PHONY: clean test install uninstall