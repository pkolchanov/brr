#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include "microui.h"
#include "render.h"
#include "ui.h"

mu_Context *ctx = &(mu_Context){0};
static render_context_t render_context;

void fill_bg(uint8_t *buffer, int width, int height){
    uint32_t bg_color = ((int)bg[0] << 16) | ((int)bg[1] << 8) | (int)bg[2];
    uint32_t *ptr = (uint32_t*)buffer;
    for (int i = 0; i < width * height; i++){
        *ptr = bg_color;
        ptr++;
    }
}

void frame(uint8_t *buffer, int width, int height)
{
    render_context.buffer = buffer;
    render_context.w = width;
    render_context.h = height;
    process_frame(ctx);
    
    fill_bg(buffer, width, height);
    mu_Command *cmd = NULL;
    while (mu_next_command(ctx, &cmd))
    {
        switch (cmd->type)
        {
        case MU_COMMAND_TEXT:
            r_draw_text(&render_context, cmd->text.str, cmd->text.pos, cmd->text.color);
            break;
        case MU_COMMAND_RECT:
            r_draw_rect(&render_context, cmd->rect.rect, cmd->rect.color);
            break;
        case MU_COMMAND_ICON:
            r_draw_icon(&render_context, cmd->icon.id, cmd->icon.rect, cmd->icon.color);
            break;
        case MU_COMMAND_CLIP:
            r_set_clip_rect(&render_context, cmd->clip.rect);
            break;
        }
    }

}

int brr_to_microui_keycode(brr_keycode keycode)
{
    switch (keycode)
    {
    case BRR_KEY_LEFT_SHIFT:
    case BRR_KEY_RIGHT_SHIFT:
        return MU_KEY_SHIFT;

    case BRR_KEY_LEFT_CONTROL:
    case BRR_KEY_RIGHT_CONTROL:
        return MU_KEY_CTRL;

    case BRR_KEY_LEFT_ALT:
    case BRR_KEY_RIGHT_ALT:
        return MU_KEY_ALT;

    case BRR_KEY_ENTER:
        return MU_KEY_RETURN;

    case BRR_KEY_BACKSPACE:
        return MU_KEY_BACKSPACE;
    default:
        0;
    }
    return 0;
}

int brr_to_microui_mousebutton(brr_mouse_button mousebutton)
{
    switch (mousebutton)
    {
    case BRR_MOUSE_BUTTON_LEFT:
        return MU_MOUSE_LEFT;
    case BRR_MOUSE_BUTTON_RIGHT:
        return MU_MOUSE_RIGHT;
    case BRR_MOUSE_BUTTON_MIDDLE:
        return MU_MOUSE_MIDDLE;
    default:
        0;
    }
    return 0;
}

void event(brr_event *ev)
{
    switch (ev->event_type)
    {
    case BRR_EV_KEYDOWN:
    case BRR_EV_KEYUP:
    {
        int c = brr_to_microui_keycode(ev->keycode);
        if (c && ev->event_type == BRR_EV_KEYDOWN)
        {
            mu_input_keydown(ctx, c);
            return;
        }
        if (c && ev->event_type == BRR_EV_KEYUP)
        {
            mu_input_keyup(ctx, c);
            return;
        }
        if (c == 0 && ev->event_type == BRR_EV_KEYDOWN)
        {
            mu_input_text(ctx, (char[]){(char)ev->keycode, '\0'});
            return;
        }
        break;
    }
    case BRR_EV_MOUSEDOWN:
    case BRR_EV_MOUSEUP:
    {
        int b = brr_to_microui_mousebutton(ev->mouse_button);
        if (b && ev->event_type == BRR_EV_MOUSEDOWN)
        {
            mu_input_mousedown(ctx, ev->mouse_x, ev->mouse_y, b);
        }
        if (b && ev->event_type == BRR_EV_MOUSEUP)
        {
            mu_input_mouseup(ctx, ev->mouse_x, ev->mouse_y, b);
        }
        break;
    }
    case BRR_EV_MOUSEMOVED:
        mu_input_mousemove(ctx, ev->mouse_x, ev->mouse_y);
        break;

    default:
        break;
    }
}


int main(int argc, const char *argv[])
{
    mu_init(ctx);
    ctx->text_width = r_text_width;
    ctx->text_height = r_text_height;
    brr_start("brr microui", 320, 200, frame, event, NULL);
}