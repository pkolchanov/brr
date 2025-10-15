<img src="./cairo.png" width="320" />

# brr cairo
Simple cairo vector shape rendeing with brr.h 

#### Build 
```bash
# macOS
gcc -x objective-c -framework Cocoa $(pkg-config --cflags --libs cairo) cairo.c -o cairo && ./cairo
```
