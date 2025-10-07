#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define pi M_PI

static float t = 0;
const float speed_x = 2.2;
const float speed_y = -3.1;
const float speed_xy = 1.8;
const float speed_phase = 0.08f;

void frame(uint8_t *buffer, int width, int height){
    for(int y=0; y<height; y++){
        float ny = (float)y / (float)height;
        for(int x=0; x<width; x++)
		{
            float nx = (float)x / (float)width;
            float v = sinf(nx * 2.0f * pi + t * speed_x) + sinf(ny * 2.0f * pi + t * speed_y) + sinf((nx + ny)*pi + t * speed_xy);
            float u = (v + 3.0f) * (1.0f / 6); 
			
            float p = u + t * speed_phase;
            float r = 0.5f + 0.5f * sinf(2.f * pi * (p + 0.00f));
            float g = 0.5f + 0.5f * sinf(2.f * pi * (p + 0.33f));
            float b = 0.5f + 0.5f * sinf(2.f * pi * (p + 0.66f));

            int idx = (y * width + x) * BRR_BYTES_PER_PIXEL;
            buffer[idx    ] = (uint8_t)(255.f * r);
            buffer[idx + 1] = (uint8_t)(255.f * g);
            buffer[idx + 2] = (uint8_t)(255.f * b);
		}
    }
        
    t += 0.01f;
}

int main(int argc, const char * argv[]) {
    brr_start("brr plasma", 320, 200, frame, NULL);
}