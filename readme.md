# brr.h

brr.h is a single-header application wrapper for software rendering apps. It supports macOS (Core Graphics), linux (x11), and windows (GDI). 


## Minimal example

```c
#define BRR_IMPLEMENTATION
#include "brr.h"

static int r = 128;

void frame(uint8_t *buffer, int width, int height){
    int idx = 0;
    while (idx < width * height * BRR_BYTES_PER_PIXEL){
        buffer[idx]     = 0;       // BLUE
        buffer[idx + 1] = 0;       // GREEN
        buffer[idx + 2] = r % 255; // RED
        
        idx += BRR_BYTES_PER_PIXEL;
    }
}

void event(brr_event *event){
    switch (event->keycode) {
        case BRR_KEY_UP:
            r += 3;
            break;
        case BRR_KEY_DOWN:
            r -= 3;
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    brr_start("hi brr", 320, 200, frame, event);
}

```

## Build 
```bash
# macOS
gcc -x objective-c -framework Cocoa main.c -o main && ./main

# linux
gcc main.c -lX11 -lXext -o main && ./main

# windows (MSVC)
cl main.c && main.exe

# windows (mingw)
gcc main.c -mwindows -o main.exe && ./main.exe
```
