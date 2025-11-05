#include "microui.h"
#include "../../utils/microtext.h"

microtext_surface surface;

typedef struct render_context_t
{
    int clipx;
    int clipy;
    int clipw;
    int cliph;

    int w;
    int h;
    uint8_t *buffer;
} render_context_t;


static void r_set_pixel(render_context_t *render_context, int x, int y, mu_Color color){
    if (x >= (render_context->clipw + render_context->clipx ) || 
            x < render_context->clipx ||
            y >= (render_context->cliph + render_context->clipy) ||
            y < render_context->clipy ||
            x < 0 ||
            y < 0 || 
            x >= render_context->w ||
            y >= render_context->h){
        return;
    }
    int idx = ( y * render_context->w + x) * BRR_BYTES_PER_PIXEL;
    if (idx - 2 < render_context->w * render_context->h * BRR_BYTES_PER_PIXEL){
        render_context->buffer[idx] = color.b;
        render_context->buffer[idx+1] = color.g;
        render_context->buffer[idx+2] = color.r;
    }
};

void r_draw_rect(render_context_t *render_context, mu_Rect rect, mu_Color color)
{
    for (int y = rect.y; y < rect.y + rect.h; y++){
        for (int x = rect.x; x < rect.x + rect.w; x++){
            r_set_pixel(render_context, x, y, color);
        }
    }
}

void r_draw_text(render_context_t *render_context, const char *text, mu_Vec2 pos, mu_Color color)
{
    if (! microtext_init_surface(&surface, render_context->w, MICROTEXT_CHAR_HEIGHT)){
        return;
    }
    microtext_put_text(&surface, text);
    for (int y = 0; y < MICROTEXT_CHAR_HEIGHT; y++){
        for (int x = 0; x < surface.width; x++){
            int src_idx = y * surface.width + x;
            if (surface.buffer[src_idx] == 255 ){
                    r_set_pixel(render_context, x + pos.x, y + pos.y, color);
            }
        }
    }
}

static const uint8_t icons[32] = {
  0xC3, 0xE7, 0x76, 0x38, 0x1C, 0x6E, 0xE7, 0xC3,
  0x00, 0x00, 0x03, 0x07, 0xCE, 0xFC, 0x78, 0x30,
  0x00, 0x00, 0x00, 0xC3, 0xE7, 0x7E, 0x3C, 0x18,
  0x30, 0x38, 0x1C, 0x0E, 0x0E, 0x1C, 0x38, 0x30, 
};

#define ICON_WIDTH 8
#define ICON_HEIGHT 8

int get_icon_idx(int id){
    int idx = -1;
    switch (id)
    {
    case MU_ICON_CLOSE:
        idx = 0;
        break;
    case MU_ICON_CHECK:
        idx = 1;
        break;
    case MU_ICON_COLLAPSED:
        idx = 2;
        break;
    case MU_ICON_EXPANDED:
        idx = 3;
        break;
    default:
        break;
    }
    return idx;
}

void r_draw_icon(render_context_t *render_context, int id, mu_Rect rect, mu_Color color)
{
    int idx = get_icon_idx(id);
    if (idx < 0){
        return;
    }
    int font_idx = idx * ICON_HEIGHT;
    for (int row = 0; row < ICON_HEIGHT; row++){
        uint8_t lint = icons[font_idx + row];
        
        for (int bit = ICON_WIDTH - 1; bit >= 0; bit--) {
            uint8_t val = (lint & (1 << bit)) ? 255 : 0;
            if (val){
                r_set_pixel(render_context, rect.x + (ICON_WIDTH - 1 - bit) + rect.w * 0.25, rect.y + row + rect.h * 0.25, color);
            }
        }
    }
}

void r_set_clip_rect(render_context_t *render_context, mu_Rect rect)
{
    render_context->clipx = rect.x;
    render_context->clipy = rect.y;
    render_context->clipw = rect.w;
    render_context->cliph = rect.h;
}

int r_text_width(mu_Font font, const char *text, int len)
{
    int res = 0;
    for (const char *p = text; *p && len--; p++) {
        if ((*p & 0xc0) == 0x80) { continue; }
        int chr = mu_min((unsigned char) *p, 127);
        res += MICROTEXT_CHAR_WIDTH;
    }
    return res;
}

int r_text_height(mu_Font font)
{
    return MICROTEXT_CHAR_HEIGHT;
}