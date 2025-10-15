<img src="./cairo.png" width="320" />

# brr cairo
A cairo graphics vector shape rendering with brr.h 

#### Build 
```bash
# macOS
gcc -x objective-c -framework Cocoa $(pkg-config --cflags --libs cairo) cairo.c -o cairo && ./cairo§

# linux
gcc cairo.c -lX11 -lXext  -lm $(pkg-config --cflags --libs cairo) -o cairo && ./cairo
```
