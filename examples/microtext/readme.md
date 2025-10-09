<img src="./microtext.png" width="320" />

# brr microtext
A simple text renderer for brr.h

#### Build 
```bash
# macOS
gcc -x objective-c -framework Cocoa microtext.c -o microtext && ./microtext

# linux
gcc microtext.c -lX11 -lXext -o microtext && ./microtext

# windows (MSVC)
cl microtext.c && microtext.exe

# windows (mingw)
gcc microtext.c -mwindows -o microtext.exe && ./microtext.exe
```
