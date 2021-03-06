
# img

  image dimension reader.

## Why?

 Because I'm lazy. Typically CSS compilers like SASS and Stylus support functions that allow you to read image dimensions directly in the language, however if and when you are working with regular CSS this can be a pain in the ass.

## Installation

    $ make install

## Usage

```

Usage: img <path>

```

## Examples

```bash
$ img test/firefox.png 
width: 350px;
height: 279px;
```

## Format support

 Currently only __PNG__ and __GIF__ are supported, because it's
 pretty rare (for myself at least) to use JPEGs or others in
 CSS, though feel free to submit a pull-request.

## License 

(The MIT License)

Copyright (c) 2011 TJ Holowaychuk &lt;tj@vision-media.ca&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.