#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include <cairo.h>
#include <math.h>

static cairo_surface_t *surface;
static cairo_t *cr;
static int last_width = 0;
static int last_height = 0;
float t = 1.0;

void destroy_surface(){
    if (surface){
        cairo_destroy (cr);
        cairo_surface_destroy (surface);
        cr = NULL;
        surface = NULL;
    }
}

void create_surface(int width, int height){
    if (surface){
        destroy_surface();
    }
    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create (surface);
    last_height = height;
    last_width = width;
}

static void draw_shape(cairo_t *cr) {
    cairo_move_to(cr, 109.0, 520.0);
    cairo_curve_to(cr, 162.0, 520.0, 242.0, 492.0, 297.0, 466.0);
    cairo_curve_to(cr, 297.0, 503.0, 311.0, 516.0, 343.0, 516.0);
    cairo_curve_to(cr, 375.0, 516.0, 519.0, 503.0, 531.0, 466.0);
    cairo_curve_to(cr, 539.0, 441.0, 543.0, 384.0, 543.0, 324.0);
    cairo_curve_to(cr, 543.0, 121.0, 493.0,   0.0, 284.0,   0.0);
    cairo_curve_to(cr, 136.0,   0.0,  21.0,  53.0,  11.0, 108.0);
    cairo_curve_to(cr,   9.0, 116.0,   9.0, 128.0,   9.0, 131.0);
    cairo_curve_to(cr,   9.0, 188.0,  29.0, 254.0,  48.0, 254.0);
    cairo_curve_to(cr,  51.0, 254.0,  54.0, 252.0,  57.0, 249.0);
    cairo_curve_to(cr, 110.0, 187.0, 210.0, 165.0, 259.0, 164.0);
    cairo_curve_to(cr,  86.0, 240.0,   0.0, 296.0,   0.0, 396.0);
    cairo_curve_to(cr,   0.0, 448.0,  21.0, 520.0, 109.0, 520.0);
    cairo_close_path(cr);

    cairo_move_to(cr, 276.0, 398.0);
    cairo_curve_to(cr, 255.0, 404.0, 252.0, 384.0, 252.0, 353.0);
    cairo_curve_to(cr, 252.0, 296.0, 260.0, 243.0, 286.0, 222.0);
    cairo_line_to  (cr, 286.0, 395.0);
    cairo_line_to  (cr, 276.0, 398.0);
    cairo_close_path(cr);

    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_set_antialias(cr, CAIRO_ANTIALIAS_BEST);
    cairo_fill(cr);
}

void frame(uint8_t *buffer, int width, int height){
    if (!surface || width != last_width || height != last_height){
        create_surface(width, height);
    }
    cairo_save(cr);   
    cairo_scale(cr, (sin(t) + 2) * 0.25, (sin(t) + 2) * 0.25);  
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    cairo_paint (cr);
    draw_shape(cr);
    cairo_surface_flush(surface);
    cairo_restore(cr);     

    uint8_t *data = cairo_image_surface_get_data(surface);
    memcpy(buffer, data, width * height * BRR_BYTES_PER_PIXEL);
    t += 0.01;
}


int main(int argc, const char * argv[]) {
    brr_start("brr cairo", 320, 200, frame, NULL, destroy_surface);
}