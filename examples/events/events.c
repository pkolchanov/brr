#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include "../../utils/microtext.h"

const char* brr_event_type_to_str(brr_event_type event_type){
    switch (event_type)
    {
        case BRR_EV_KEYDOWN:
            return "KEY_DOWN";
        case BRR_EV_KEYUP:
            return "KEY_UP";
        case BRR_EV_MOUSEDOWN:
            return "MOUSE_DOWN";
        case BRR_EV_MOUSEUP:
            return "MOUSE_UP";
        case BRR_EV_MOUSEMOVED:
            return "MOUSE_MOVED";
        default:
        break;
    }
    return "?";
}

const char* brr_mouse_button_to_str(brr_mouse_button mouse_button){
    switch (mouse_button)
    {
        case BRR_MOUSE_BUTTON_LEFT:
            return "LEFT";
        case BRR_MOUSE_BUTTON_RIGHT:
            return "RIGHT";
        case BRR_MOUSE_BUTTON_MIDDLE:
            return "MIDDLE";
        case BRR_MOUSE_BUTTON_OTHER:
            return "OTHER";
        default:
        break;
    }
    return "?";
}

const char* brr_keycode_to_str(brr_keycode keycode){
    switch (keycode)
    {
        case BRR_KEY_UNKNOWN: return "UNKNOWN";
        case BRR_KEY_SPACE: return "SPACE";
        case BRR_KEY_APOSTROPHE: return "APOSTROPHE";
        case BRR_KEY_COMMA: return "COMMA";
        case BRR_KEY_MINUS: return "MINUS";
        case BRR_KEY_PERIOD: return "PERIOD";
        case BRR_KEY_SLASH: return "SLASH";
        case BRR_KEY_0: return "0";
        case BRR_KEY_1: return "1";
        case BRR_KEY_2: return "2";
        case BRR_KEY_3: return "3";
        case BRR_KEY_4: return "4";
        case BRR_KEY_5: return "5";
        case BRR_KEY_6: return "6";
        case BRR_KEY_7: return "7";
        case BRR_KEY_8: return "8";
        case BRR_KEY_9: return "9";
        case BRR_KEY_SEMICOLON: return "SEMICOLON";
        case BRR_KEY_EQUAL: return "EQUAL";
        case BRR_KEY_A: return "A";
        case BRR_KEY_B: return "B";
        case BRR_KEY_C: return "C";
        case BRR_KEY_D: return "D";
        case BRR_KEY_E: return "E";
        case BRR_KEY_F: return "F";
        case BRR_KEY_G: return "G";
        case BRR_KEY_H: return "H";
        case BRR_KEY_I: return "I";
        case BRR_KEY_J: return "J";
        case BRR_KEY_K: return "K";
        case BRR_KEY_L: return "L";
        case BRR_KEY_M: return "M";
        case BRR_KEY_N: return "N";
        case BRR_KEY_O: return "O";
        case BRR_KEY_P: return "P";
        case BRR_KEY_Q: return "Q";
        case BRR_KEY_R: return "R";
        case BRR_KEY_S: return "S";
        case BRR_KEY_T: return "T";
        case BRR_KEY_U: return "U";
        case BRR_KEY_V: return "V";
        case BRR_KEY_W: return "W";
        case BRR_KEY_X: return "X";
        case BRR_KEY_Y: return "Y";
        case BRR_KEY_Z: return "Z";
        case BRR_KEY_LEFT_BRACKET: return "LEFT_BRACKET";
        case BRR_KEY_BACKSLASH: return "BACKSLASH";
        case BRR_KEY_RIGHT_BRACKET: return "RIGHT_BRACKET";
        case BRR_KEY_GRAVE_ACCENT: return "GRAVE_ACCENT";
        case BRR_KEY_WORLD_1: return "WORLD_1";
        case BRR_KEY_WORLD_2: return "WORLD_2";
        case BRR_KEY_ESCAPE: return "ESCAPE";
        case BRR_KEY_ENTER: return "ENTER";
        case BRR_KEY_TAB: return "TAB";
        case BRR_KEY_BACKSPACE: return "BACKSPACE";
        case BRR_KEY_INSERT: return "INSERT";
        case BRR_KEY_DELETE: return "DELETE";
        case BRR_KEY_RIGHT: return "RIGHT";
        case BRR_KEY_LEFT: return "LEFT";
        case BRR_KEY_DOWN: return "DOWN";
        case BRR_KEY_UP: return "UP";
        case BRR_KEY_PAGE_UP: return "PAGE_UP";
        case BRR_KEY_PAGE_DOWN: return "PAGE_DOWN";
        case BRR_KEY_HOME: return "HOME";
        case BRR_KEY_END: return "END";
        case BRR_KEY_CAPS_LOCK: return "CAPS_LOCK";
        case BRR_KEY_SCROLL_LOCK: return "SCROLL_LOCK";
        case BRR_KEY_NUM_LOCK: return "NUM_LOCK";
        case BRR_KEY_PRINT_SCREEN: return "PRINT_SCREEN";
        case BRR_KEY_PAUSE: return "PAUSE";
        case BRR_KEY_F1: return "F1";
        case BRR_KEY_F2: return "F2";
        case BRR_KEY_F3: return "F3";
        case BRR_KEY_F4: return "F4";
        case BRR_KEY_F5: return "F5";
        case BRR_KEY_F6: return "F6";
        case BRR_KEY_F7: return "F7";
        case BRR_KEY_F8: return "F8";
        case BRR_KEY_F9: return "F9";
        case BRR_KEY_F10: return "F10";
        case BRR_KEY_F11: return "F11";
        case BRR_KEY_F12: return "F12";
        case BRR_KEY_F13: return "F13";
        case BRR_KEY_F14: return "F14";
        case BRR_KEY_F15: return "F15";
        case BRR_KEY_F16: return "F16";
        case BRR_KEY_F17: return "F17";
        case BRR_KEY_F18: return "F18";
        case BRR_KEY_F19: return "F19";
        case BRR_KEY_F20: return "F20";
        case BRR_KEY_F21: return "F21";
        case BRR_KEY_F22: return "F22";
        case BRR_KEY_F23: return "F23";
        case BRR_KEY_F24: return "F24";
        case BRR_KEY_F25: return "F25";
        case BRR_KEY_KP_0: return "KP_0";
        case BRR_KEY_KP_1: return "KP_1";
        case BRR_KEY_KP_2: return "KP_2";
        case BRR_KEY_KP_3: return "KP_3";
        case BRR_KEY_KP_4: return "KP_4";
        case BRR_KEY_KP_5: return "KP_5";
        case BRR_KEY_KP_6: return "KP_6";
        case BRR_KEY_KP_7: return "KP_7";
        case BRR_KEY_KP_8: return "KP_8";
        case BRR_KEY_KP_9: return "KP_9";
        case BRR_KEY_KP_DECIMAL: return "KP_DECIMAL";
        case BRR_KEY_KP_DIVIDE: return "KP_DIVIDE";
        case BRR_KEY_KP_MULTIPLY: return "KP_MULTIPLY";
        case BRR_KEY_KP_SUBTRACT: return "KP_SUBTRACT";
        case BRR_KEY_KP_ADD: return "KP_ADD";
        case BRR_KEY_KP_ENTER: return "KP_ENTER";
        case BRR_KEY_KP_EQUAL: return "KP_EQUAL";
        case BRR_KEY_LEFT_SHIFT: return "LEFT_SHIFT";
        case BRR_KEY_LEFT_CONTROL: return "LEFT_CONTROL";
        case BRR_KEY_LEFT_ALT: return "LEFT_ALT";
        case BRR_KEY_LEFT_SUPER: return "LEFT_SUPER";
        case BRR_KEY_RIGHT_SHIFT: return "RIGHT_SHIFT";
        case BRR_KEY_RIGHT_CONTROL: return "RIGHT_CONTROL";
        case BRR_KEY_RIGHT_ALT: return "RIGHT_ALT";
        case BRR_KEY_RIGHT_SUPER: return "RIGHT_SUPER";
        case BRR_KEY_MENU: return "MENU";
        default:
            break;
    }
    return "?";
}

char buf[256];
brr_event last_event;
microtext_surface surface;

void frame(uint8_t *buffer, int width, int height){
    microtext_clear_surface(&surface);
    snprintf(buf, sizeof(buf), "Event type: %s\n", brr_event_type_to_str(last_event.event_type));
    microtext_put_text(&surface, buf);
    microtext_put_text(&surface, "Modifier: ");
    if (last_event.event_modifier & BRR_MOD_SHIFT){
        microtext_put_text(&surface, "SHIFT ");
    }
    if (last_event.event_modifier & BRR_MOD_CONTROL){
        microtext_put_text(&surface, "CONTROL ");
    }
    if (last_event.event_modifier & BRR_MOD_ALT){
        microtext_put_text(&surface, "ALT ");
    }
    if (last_event.event_modifier & BRR_MOD_SUPER){
        microtext_put_text(&surface, "SUPER ");
    }
    if (last_event.event_modifier & BRR_MOD_MOUSE_LEFT){
        microtext_put_text(&surface, "MOUSE_LEFT ");
    }    
    if (last_event.event_modifier & BRR_MOD_MOUSE_RIGHT){
        microtext_put_text(&surface, "MOUSE_RIGHT ");
    }    
    if (last_event.event_modifier & BRR_MOD_MOUSE_MIDDLE){
        microtext_put_text(&surface, "MOUSE_MIDDLE ");
    }
    if (last_event.event_modifier == 0){
         microtext_put_text(&surface, "0 ");
    }
    microtext_put_text(&surface, "\n");

    snprintf(buf, sizeof(buf), "Key code: %s\n", brr_keycode_to_str(last_event.keycode));
    microtext_put_text(&surface, buf);
    snprintf(buf, sizeof(buf), "Repeat: %d\n", last_event.key_repeat);
    microtext_put_text(&surface, buf);
    snprintf(buf, sizeof(buf), "Mouse button: %s\n", brr_mouse_button_to_str(last_event.mouse_button));
    microtext_put_text(&surface, buf);
    snprintf(buf, sizeof(buf), "Mouse X: %.2f\n", last_event.mouse_x);
    microtext_put_text(&surface, buf);
    snprintf(buf, sizeof(buf), "Mouse Y: %.2f\n", last_event.mouse_y);
    microtext_put_text(&surface, buf);

    for(int y = 0; y < height; y++){
        for(int  x = 0; x < width; x++){
            int src_x = x *  surface.width / width;
            int src_y = y *  surface.height / height ;
            int src_idx = src_y * surface.width + src_x;
            int dest_idx = (y * width + x) * BRR_BYTES_PER_PIXEL;
            uint8_t src = surface.buffer[src_idx];

            buffer[dest_idx    ] = src;
            buffer[dest_idx + 1] = src;
            buffer[dest_idx + 2] = src;
        }
    }
}

void event(brr_event *event){
    last_event = *event;
}

int main(int argc, const char * argv[]) {
    memset(&last_event, 0, sizeof(brr_event));
    microtext_init_surface(&surface, 320, 200);
    brr_start("brr events", 320, 200, frame, event, NULL);
}