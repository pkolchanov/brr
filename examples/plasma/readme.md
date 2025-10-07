<img src="./plasma.png" width="320" />

# brr.h plasma
A classic demoscene–style plasma effect for brr.h

#### Build 
```bash
# macOS
gcc -x objective-c -framework Cocoa plasma.c -o plasma && ./plasma

# linux
gcc plasma.c -lX11 -lXext -o plasma && ./plasma

# windows (MSVC)
cl plasma.c && plasma.exe

# windows (mingw)
gcc plasma.c -mwindows -o plasma.exe && ./plasma.exe
```