brr.h: single header application wrapper library focused on software rendering. Supports macOS, linux (x11), and windows. 


## Minimal example

```
# macOS

gcc -x objective-c -framework Cocoa main.c -o main

# macOS (x11)
gcc -g -I /usr/X11/include main.c -L/usr/X11/lib -lX11  -o main && ./main

```
