#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include "../../utils/microtext.h"

microtext_surface surface;

void frame(uint8_t *buffer, int width, int height){
    microtext_clear_surface(&surface);
    microtext_put_text(&surface, "Microtext rulez!\n");
    microtext_put_text(&surface, "Yea rulez");
    for(int y = 0; y < height; y++){
        for(int  x = 0; x < width; x++){
            int src_x = x *  surface.width / width;
            int src_y = y *  surface.height / height ;
            int src_idx = src_y * surface.width + src_x;
            int dest_idx = (y * width + x) * BRR_BYTES_PER_PIXEL;

            buffer[dest_idx    ] = surface.buffer[src_idx];
            buffer[dest_idx + 1] = surface.buffer[src_idx];
            buffer[dest_idx + 2] = surface.buffer[src_idx];
        }
    }
}

int main(int argc, const char * argv[]) {
    microtext_init_surface(&surface, 320, 200);
    brr_start("brr microtext", 320, 200, frame, NULL, NULL);
}