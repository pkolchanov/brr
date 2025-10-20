# brr.h

brr.h is a single-header application wrapper for software rendering apps. 
* Creates a window and provides an API for frame rendering and event handling.
* Has no dependencies on 3D graphics APIs such as OpenGL or DirectX.
* Supports macOS (Core Graphics), Linux (x11), and Windows (GDI). 


## Minimal example

```c
#define BRR_IMPLEMENTATION
#include "brr.h"

static int r = 128;

void frame(uint8_t *buffer, int width, int height){
    // *buffer is a pointer to a frame bitmap in BGRX (Blue, Green, Red, _), 8 bits per color.
    // width, height are a bitmap dimensions in pixels

    int idx = 0;
    while (idx < width * height * BRR_BYTES_PER_PIXEL){
        buffer[idx]     = 0;       // Blue
        buffer[idx + 1] = 0;       // Green
        buffer[idx + 2] = r % 255; // Red
        
        idx += BRR_BYTES_PER_PIXEL;
    }
}

void event(brr_event *event){
    if (event->event_type == BRR_EV_KEYDOWN){
        switch (event->keycode){
            case BRR_KEY_RIGHT:
                r += 3;
                break;
            case BRR_KEY_LEFT:
                r -= 3;
                break;
            default:
                break;
        }
    }
}

int main(int argc, const char * argv[]){
    brr_start("hi brr", 320, 200, frame, event, NULL);
}

```

#### Build 
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


## Other examples
| Example | Description |
| --- | --- |
| [plasma](/examples/plasma/readme.md) | A classic demoscene–style plasma effect |
| [fire](/examples/fire/readme.md) | A classic demoscene–style fire effect |
| [events](/examples/events/readme.md) | An events inspector |
| [microtext](/examples/microtext/readme.md) | A simple text renderer |
| [cairo](/examples/cairo/readme.md) | A cairo graphics vector shape rendering |
| [DOOM](/examples/doom/readme.md) | A DOOM port based on doomgeneric by ozkl |
