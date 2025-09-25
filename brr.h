#ifndef BRR_INCL
#define BRR_INCL
#include <stdint.h> // uint8_t, uint32_t

#ifdef __cplusplus
extern "C" {
#endif

enum{
    BRR_BYTES_PER_PIXEL = 4,
    BRR_FPS = 30,
    BRR_MAX_KEYCODES = 512
};

typedef uint32_t brr_event_modifier;

typedef enum brr_event_modifier_flag{
    BRR_MOD_SHIFT = 1 << 1,
    BRR_MOD_CONTROL = 1 << 2,
    BRR_MOD_ALT = 1 << 3,
    BRR_MOD_SUPER = 1 << 4,
    BRR_MOD_MOUSE_LEFT = 1 << 5 ,
    BRR_MOD_MOUSE_RIGHT = 1 << 6,
    BRR_MOD_MOUSE_MIDDLE = 1 << 7,
} brr_event_modifier_flag;

typedef enum brr_mouse_button{
    BRR_MOUSE_BUTTON_LEFT,
    BRR_MOUSE_BUTTON_RIGHT,
    BRR_MOUSE_BUTTON_MIDDLE,
    BRR_MOUSE_BUTTON_OTHER,
} brr_mouse_button;

typedef enum brr_event_type{
    BRR_EV_KEYDOWN,
    BRR_EV_KEYUP,
    BRR_EV_MOUSEDOWN,
    BRR_EV_MOUSEUP,
    BRR_EV_MOUSEMOVED
} brr_event_type;

// Source: glfw/include/GLFW/glfw3.h
typedef enum brr_keycode{
	BRR_KEY_UNKNOWN           =  0,
    BRR_KEY_SPACE             = 32,
    BRR_KEY_APOSTROPHE        = 39,
    BRR_KEY_COMMA             = 44,
    BRR_KEY_MINUS             = 45,
    BRR_KEY_PERIOD            = 46,
    BRR_KEY_SLASH             = 47,
    BRR_KEY_0                 = 48,
    BRR_KEY_1                 = 49,
    BRR_KEY_2                 = 50,
    BRR_KEY_3                 = 51,
    BRR_KEY_4                 = 52,
    BRR_KEY_5                 = 53,
    BRR_KEY_6                 = 54,
    BRR_KEY_7                 = 55,
    BRR_KEY_8                 = 56,
    BRR_KEY_9                 = 57,
    BRR_KEY_SEMICOLON         = 59,
    BRR_KEY_EQUAL             = 61,
    BRR_KEY_A                 = 65,
    BRR_KEY_B                 = 66,
    BRR_KEY_C                 = 67,
    BRR_KEY_D                 = 68,
    BRR_KEY_E                 = 69,
    BRR_KEY_F                 = 70,
    BRR_KEY_G                 = 71,
    BRR_KEY_H                 = 72,
    BRR_KEY_I                 = 73,
    BRR_KEY_J                 = 74,
    BRR_KEY_K                 = 75,
    BRR_KEY_L                 = 76,
    BRR_KEY_M                 = 77,
    BRR_KEY_N                 = 78,
    BRR_KEY_O                 = 79,
    BRR_KEY_P                 = 80,
    BRR_KEY_Q                 = 81,
    BRR_KEY_R                 = 82,
    BRR_KEY_S                 = 83,
    BRR_KEY_T                 = 84,
    BRR_KEY_U                 = 85,
    BRR_KEY_V                 = 86,
    BRR_KEY_W                 = 87,
    BRR_KEY_X                 = 88,
    BRR_KEY_Y                 = 89,
    BRR_KEY_Z                 = 90,
    BRR_KEY_LEFT_BRACKET      = 91,
    BRR_KEY_BACKSLASH         = 92,
    BRR_KEY_RIGHT_BRACKET     = 93,
    BRR_KEY_GRAVE_ACCENT      = 96,
    BRR_KEY_WORLD_1           = 161,
    BRR_KEY_WORLD_2           = 162,

    /* Function keys */
    BRR_KEY_ESCAPE            = 256,
    BRR_KEY_ENTER             = 257,
    BRR_KEY_TAB               = 258,
    BRR_KEY_BACKSPACE         = 259,
    BRR_KEY_INSERT            = 260,
    BRR_KEY_DELETE            = 261,
    BRR_KEY_RIGHT             = 262,
    BRR_KEY_LEFT              = 263,
    BRR_KEY_DOWN              = 264,
    BRR_KEY_UP                = 265,
    BRR_KEY_PAGE_UP           = 266,
    BRR_KEY_PAGE_DOWN         = 267,
    BRR_KEY_HOME              = 268,
    BRR_KEY_END               = 269,
    BRR_KEY_CAPS_LOCK         = 280,
    BRR_KEY_SCROLL_LOCK       = 281,
    BRR_KEY_NUM_LOCK          = 282,
    BRR_KEY_PRINT_SCREEN      = 283,
    BRR_KEY_PAUSE             = 284,
    BRR_KEY_F1                = 290,
    BRR_KEY_F2                = 291,
    BRR_KEY_F3                = 292,
    BRR_KEY_F4                = 293,
    BRR_KEY_F5                = 294,
    BRR_KEY_F6                = 295,
    BRR_KEY_F7                = 296,
    BRR_KEY_F8                = 297,
    BRR_KEY_F9                = 298,
    BRR_KEY_F10               = 299,
    BRR_KEY_F11               = 300,
    BRR_KEY_F12               = 301,
    BRR_KEY_F13               = 302,
    BRR_KEY_F14               = 303,
    BRR_KEY_F15               = 304,
    BRR_KEY_F16               = 305,
    BRR_KEY_F17               = 306,
    BRR_KEY_F18               = 307,
    BRR_KEY_F19               = 308,
    BRR_KEY_F20               = 309,
    BRR_KEY_F21               = 310,
    BRR_KEY_F22               = 311,
    BRR_KEY_F23               = 312,
    BRR_KEY_F24               = 313,
    BRR_KEY_F25               = 314,
    BRR_KEY_KP_0              = 320,
    BRR_KEY_KP_1              = 321,
    BRR_KEY_KP_2              = 322,
    BRR_KEY_KP_3              = 323,
    BRR_KEY_KP_4              = 324,
    BRR_KEY_KP_5              = 325,
    BRR_KEY_KP_6              = 326,
    BRR_KEY_KP_7              = 327,
    BRR_KEY_KP_8              = 328,
    BRR_KEY_KP_9              = 329,
    BRR_KEY_KP_DECIMAL        = 330,
    BRR_KEY_KP_DIVIDE         = 331,
    BRR_KEY_KP_MULTIPLY       = 332,
    BRR_KEY_KP_SUBTRACT       = 333,
    BRR_KEY_KP_ADD            = 334,
    BRR_KEY_KP_ENTER          = 335,
    BRR_KEY_KP_EQUAL          = 336,
    BRR_KEY_LEFT_SHIFT        = 340,
    BRR_KEY_LEFT_CONTROL      = 341,
    BRR_KEY_LEFT_ALT          = 342,
    BRR_KEY_LEFT_SUPER        = 343,
    BRR_KEY_RIGHT_SHIFT       = 344,
    BRR_KEY_RIGHT_CONTROL     = 345,
    BRR_KEY_RIGHT_ALT         = 346,
    BRR_KEY_RIGHT_SUPER       = 347,
    BRR_KEY_MENU              = 348
} brr_keycode;

typedef struct brr_event{
    brr_event_type event_type;
    brr_keycode keycode;
    int key_repeat;
    brr_event_modifier event_modifier;
    brr_mouse_button mouse_button;
    float mouse_x;
    float mouse_y;
} brr_event;

typedef struct brr_app_t {
    void (*frame_cb)(uint8_t *, int, int);
    void (*event_cb)(brr_event*);
    int width;
    int height;
    brr_keycode keycodes[BRR_MAX_KEYCODES];
    const char *window_name;
    brr_event event;
} brr_app_t;

void brr_start(const char* window_name, int initial_width, int initial_height, void (*frame_cb)(uint8_t *, int, int), void (*event_cb)(brr_event *));

#ifdef __cplusplus
} // extern "C" {
#endif
#endif


#ifdef BRR_IMPLEMENTATION
#include <stdio.h>  // printf
#include <string.h> // memset

static brr_app_t brr_app;

static void brr_init_app(const char *window_name, int initial_width, int initial_height, void (*frame_cb)(uint8_t *, int, int), void (*event_cb)(brr_event *)){
    brr_app.width = initial_width;
    brr_app.height = initial_height;
    brr_app.frame_cb = frame_cb;
    brr_app.event_cb = event_cb;
    brr_app.window_name = window_name;
    memset(brr_app.keycodes, BRR_KEY_UNKNOWN, sizeof(brr_app.keycodes));
    memset(&brr_app.event, 0, sizeof(brr_event));
}

static void brr_send_key_event(brr_event_type ev_type, brr_event_modifier ev_modifier, int repeat, brr_keycode keycode){
    memset(&brr_app.event, 0, sizeof(brr_event));
    brr_app.event.event_type = ev_type;
    brr_app.event.keycode = keycode;
    brr_app.event.event_modifier = ev_modifier;
    brr_app.event.key_repeat = repeat;
    if (brr_app.event_cb){
        brr_app.event_cb(&brr_app.event);
    }
}

static void brr_send_mouse_event(brr_event_type ev_type, brr_mouse_button mouse_button, brr_event_modifier ev_modifier, float x, float y){
    memset(&brr_app.event, 0, sizeof(brr_event));
    brr_app.event.event_type = ev_type;
    brr_app.event.mouse_x = x;
    brr_app.event.mouse_y = y;
    brr_app.event.mouse_button = mouse_button;
    brr_app.event.event_modifier = ev_modifier;
    if (brr_app.event_cb){
        brr_app.event_cb(&brr_app.event);
    }
}

static brr_keycode brr_get_keycode(int scancode){
    if (scancode < 0 || scancode >= BRR_MAX_KEYCODES){
        return BRR_KEY_UNKNOWN;
    }
    return brr_app.keycodes[scancode];
}

#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>

static void brr_mac_init_keytable(void)
{
    brr_app.keycodes[0x1D] = BRR_KEY_0;
    brr_app.keycodes[0x12] = BRR_KEY_1;
    brr_app.keycodes[0x13] = BRR_KEY_2;
    brr_app.keycodes[0x14] = BRR_KEY_3;
    brr_app.keycodes[0x15] = BRR_KEY_4;
    brr_app.keycodes[0x17] = BRR_KEY_5;
    brr_app.keycodes[0x16] = BRR_KEY_6;
    brr_app.keycodes[0x1A] = BRR_KEY_7;
    brr_app.keycodes[0x1C] = BRR_KEY_8;
    brr_app.keycodes[0x19] = BRR_KEY_9;
    brr_app.keycodes[0x00] = BRR_KEY_A;
    brr_app.keycodes[0x0B] = BRR_KEY_B;
    brr_app.keycodes[0x08] = BRR_KEY_C;
    brr_app.keycodes[0x02] = BRR_KEY_D;
    brr_app.keycodes[0x0E] = BRR_KEY_E;
    brr_app.keycodes[0x03] = BRR_KEY_F;
    brr_app.keycodes[0x05] = BRR_KEY_G;
    brr_app.keycodes[0x04] = BRR_KEY_H;
    brr_app.keycodes[0x22] = BRR_KEY_I;
    brr_app.keycodes[0x26] = BRR_KEY_J;
    brr_app.keycodes[0x28] = BRR_KEY_K;
    brr_app.keycodes[0x25] = BRR_KEY_L;
    brr_app.keycodes[0x2E] = BRR_KEY_M;
    brr_app.keycodes[0x2D] = BRR_KEY_N;
    brr_app.keycodes[0x1F] = BRR_KEY_O;
    brr_app.keycodes[0x23] = BRR_KEY_P;
    brr_app.keycodes[0x0C] = BRR_KEY_Q;
    brr_app.keycodes[0x0F] = BRR_KEY_R;
    brr_app.keycodes[0x01] = BRR_KEY_S;
    brr_app.keycodes[0x11] = BRR_KEY_T;
    brr_app.keycodes[0x20] = BRR_KEY_U;
    brr_app.keycodes[0x09] = BRR_KEY_V;
    brr_app.keycodes[0x0D] = BRR_KEY_W;
    brr_app.keycodes[0x07] = BRR_KEY_X;
    brr_app.keycodes[0x10] = BRR_KEY_Y;
    brr_app.keycodes[0x06] = BRR_KEY_Z;

    brr_app.keycodes[0x27] = BRR_KEY_APOSTROPHE;
    brr_app.keycodes[0x2A] = BRR_KEY_BACKSLASH;
    brr_app.keycodes[0x2B] = BRR_KEY_COMMA;
    brr_app.keycodes[0x18] = BRR_KEY_EQUAL;
    brr_app.keycodes[0x32] = BRR_KEY_GRAVE_ACCENT;
    brr_app.keycodes[0x21] = BRR_KEY_LEFT_BRACKET;
    brr_app.keycodes[0x1B] = BRR_KEY_MINUS;
    brr_app.keycodes[0x2F] = BRR_KEY_PERIOD;
    brr_app.keycodes[0x1E] = BRR_KEY_RIGHT_BRACKET;
    brr_app.keycodes[0x29] = BRR_KEY_SEMICOLON;
    brr_app.keycodes[0x2C] = BRR_KEY_SLASH;
    brr_app.keycodes[0x0A] = BRR_KEY_WORLD_1;

    brr_app.keycodes[0x33] = BRR_KEY_BACKSPACE;
    brr_app.keycodes[0x39] = BRR_KEY_CAPS_LOCK;
    brr_app.keycodes[0x75] = BRR_KEY_DELETE;
    brr_app.keycodes[0x7D] = BRR_KEY_DOWN;
    brr_app.keycodes[0x77] = BRR_KEY_END;
    brr_app.keycodes[0x24] = BRR_KEY_ENTER;
    brr_app.keycodes[0x35] = BRR_KEY_ESCAPE;
    brr_app.keycodes[0x7A] = BRR_KEY_F1;
    brr_app.keycodes[0x78] = BRR_KEY_F2;
    brr_app.keycodes[0x63] = BRR_KEY_F3;
    brr_app.keycodes[0x76] = BRR_KEY_F4;
    brr_app.keycodes[0x60] = BRR_KEY_F5;
    brr_app.keycodes[0x61] = BRR_KEY_F6;
    brr_app.keycodes[0x62] = BRR_KEY_F7;
    brr_app.keycodes[0x64] = BRR_KEY_F8;
    brr_app.keycodes[0x65] = BRR_KEY_F9;
    brr_app.keycodes[0x6D] = BRR_KEY_F10;
    brr_app.keycodes[0x67] = BRR_KEY_F11;
    brr_app.keycodes[0x6F] = BRR_KEY_F12;
    brr_app.keycodes[0x69] = BRR_KEY_PRINT_SCREEN;
    brr_app.keycodes[0x6B] = BRR_KEY_F14;
    brr_app.keycodes[0x71] = BRR_KEY_F15;
    brr_app.keycodes[0x6A] = BRR_KEY_F16;
    brr_app.keycodes[0x40] = BRR_KEY_F17;
    brr_app.keycodes[0x4F] = BRR_KEY_F18;
    brr_app.keycodes[0x50] = BRR_KEY_F19;
    brr_app.keycodes[0x5A] = BRR_KEY_F20;
    brr_app.keycodes[0x73] = BRR_KEY_HOME;
    brr_app.keycodes[0x72] = BRR_KEY_INSERT;
    brr_app.keycodes[0x7B] = BRR_KEY_LEFT;
    brr_app.keycodes[0x3A] = BRR_KEY_LEFT_ALT;
    brr_app.keycodes[0x3B] = BRR_KEY_LEFT_CONTROL;
    brr_app.keycodes[0x38] = BRR_KEY_LEFT_SHIFT;
    brr_app.keycodes[0x37] = BRR_KEY_LEFT_SUPER;
    brr_app.keycodes[0x6E] = BRR_KEY_MENU;
    brr_app.keycodes[0x47] = BRR_KEY_NUM_LOCK;
    brr_app.keycodes[0x79] = BRR_KEY_PAGE_DOWN;
    brr_app.keycodes[0x74] = BRR_KEY_PAGE_UP;
    brr_app.keycodes[0x7C] = BRR_KEY_RIGHT;
    brr_app.keycodes[0x3D] = BRR_KEY_RIGHT_ALT;
    brr_app.keycodes[0x3E] = BRR_KEY_RIGHT_CONTROL;
    brr_app.keycodes[0x3C] = BRR_KEY_RIGHT_SHIFT;
    brr_app.keycodes[0x36] = BRR_KEY_RIGHT_SUPER;
    brr_app.keycodes[0x31] = BRR_KEY_SPACE;
    brr_app.keycodes[0x30] = BRR_KEY_TAB;
    brr_app.keycodes[0x7E] = BRR_KEY_UP;

    brr_app.keycodes[0x52] = BRR_KEY_KP_0;
    brr_app.keycodes[0x53] = BRR_KEY_KP_1;
    brr_app.keycodes[0x54] = BRR_KEY_KP_2;
    brr_app.keycodes[0x55] = BRR_KEY_KP_3;
    brr_app.keycodes[0x56] = BRR_KEY_KP_4;
    brr_app.keycodes[0x57] = BRR_KEY_KP_5;
    brr_app.keycodes[0x58] = BRR_KEY_KP_6;
    brr_app.keycodes[0x59] = BRR_KEY_KP_7;
    brr_app.keycodes[0x5B] = BRR_KEY_KP_8;
    brr_app.keycodes[0x5C] = BRR_KEY_KP_9;
    brr_app.keycodes[0x45] = BRR_KEY_KP_ADD;
    brr_app.keycodes[0x41] = BRR_KEY_KP_DECIMAL;
    brr_app.keycodes[0x4B] = BRR_KEY_KP_DIVIDE;
    brr_app.keycodes[0x4C] = BRR_KEY_KP_ENTER;
    brr_app.keycodes[0x51] = BRR_KEY_KP_EQUAL;
    brr_app.keycodes[0x43] = BRR_KEY_KP_MULTIPLY;
    brr_app.keycodes[0x4E] = BRR_KEY_KP_SUBTRACT;
}

@interface BrrAppDelegate : NSObject <NSApplicationDelegate>{
    NSWindow *window;
}
@end

@interface BrrView : NSView{
    NSEventModifierFlags oldFlags;
    CGContextRef contextRef;
    CGColorSpaceRef colorSpaceRef;
    uint8_t *buffer;
}
@property (strong) NSTimer *timer;
@end

@implementation BrrAppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    NSString *windowName = [NSString stringWithUTF8String:brr_app.window_name];
    window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, brr_app.width, brr_app.height)
                                         styleMask:(NSWindowStyleMaskTitled |
                                                    NSWindowStyleMaskClosable |
                                                    NSWindowStyleMaskResizable)
                                           backing:NSBackingStoreBuffered
                                             defer:NO];
    [window setAcceptsMouseMovedEvents:YES];
    BrrView *view = [[BrrView alloc] initWithFrame:[[window contentView] bounds]];
    [view setWantsLayer:YES];
    view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
    [window setContentView:view];
    [window setTitle:windowName];
    [window makeKeyAndOrderFront:nil];
    [window makeFirstResponder:view];
}

- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}
@end

@implementation BrrView
- (instancetype)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        colorSpaceRef = CGColorSpaceCreateDeviceRGB();
        // todo CADisplayLink or CVDisplayLink
        _timer = [NSTimer scheduledTimerWithTimeInterval: 1.0/BRR_FPS
                        target: self
                        selector:@selector(onTick:)
                        userInfo: nil repeats:YES];
    }
    return self;
}

-(void)onTick:(NSTimer *)timer {
    [self setNeedsDisplay:YES];
}

-(brr_event_modifier)getModifier:(NSEvent *)event{
    brr_event_modifier result = 0;
    NSUInteger b = [NSEvent pressedMouseButtons];
    if (event.modifierFlags & NSEventModifierFlagShift){
        result |= BRR_MOD_SHIFT;
    }
    if (event.modifierFlags & NSEventModifierFlagControl){
        result |= BRR_MOD_CONTROL;
    }
    if (event.modifierFlags & NSEventModifierFlagOption){
        result |= BRR_MOD_ALT;
    }
    if (event.modifierFlags & NSEventModifierFlagCommand){
        result |= BRR_MOD_SUPER;
    }
    if (b & (1 << 0)){
        result |= BRR_MOD_MOUSE_LEFT;
    }
    if (b & (1 << 1)){
        result |= BRR_MOD_MOUSE_RIGHT;
    }
    if (b & (1 << 2)){
        result |= BRR_MOD_MOUSE_MIDDLE;
    }
    return result;
}

- (void)keyDown:(NSEvent *)event{
    brr_send_key_event(BRR_EV_KEYDOWN, [self getModifier:event], [event isARepeat] ? 1 : 0, brr_get_keycode(event.keyCode));
}

- (void)keyUp:(NSEvent *)event{
    brr_send_key_event(BRR_EV_KEYUP, [self getModifier:event], [event isARepeat] ? 1 : 0, brr_get_keycode(event.keyCode));
}

- (void)flagsChanged:(NSEvent *)event {
    BOOL down = NO;
    brr_keycode keyCode = BRR_KEY_UNKNOWN;
    NSEventModifierFlags newFlags = [event modifierFlags];
    if ((oldFlags ^ newFlags) & NSEventModifierFlagShift) {
        keyCode = BRR_KEY_RIGHT_SHIFT;
        down = 0 != (newFlags & NSEventModifierFlagShift);
    }
    if ((oldFlags ^ newFlags) & NSEventModifierFlagControl) {
        keyCode = BRR_KEY_RIGHT_CONTROL;
        down = 0 != (newFlags & NSEventModifierFlagControl);
    }
    if ((oldFlags ^ newFlags) & NSEventModifierFlagOption) {
        keyCode = BRR_KEY_RIGHT_ALT;
        down = 0 != (newFlags & NSEventModifierFlagOption);
    }
    if ((oldFlags ^ newFlags) & NSEventModifierFlagCommand) {
        keyCode = BRR_KEY_RIGHT_SUPER;
        down = 0 != (newFlags & NSEventModifierFlagCommand);
    }
    if (keyCode > 0){
        brr_send_key_event(down ? BRR_EV_KEYDOWN : BRR_EV_KEYUP, [self getModifier:event], 0, keyCode);
    }
    oldFlags = [event modifierFlags];
}

-(void)updateLayer{
    if (brr_app.frame_cb) {
        brr_app.frame_cb(buffer, brr_app.width, brr_app.height);
    }
    CGImageRef image = CGBitmapContextCreateImage(contextRef);
    [[self layer] setContents:(__bridge id)image];
    CGImageRelease(image);
}

- (void)setFrameSize:(NSSize)newSize{
    brr_app.width = newSize.width;
    brr_app.height = newSize.height;
    [self reallocBuffer];
    [super setFrameSize:newSize];
}

-(void)reallocBuffer{
    if (buffer){
        CGContextRelease(contextRef);
        free(buffer);
        buffer = NULL;
    }
    size_t bitmapSize = sizeof(uint8_t) * brr_app.width * BRR_BYTES_PER_PIXEL * brr_app.height;
    buffer = (uint8_t*) malloc(bitmapSize);
    contextRef = CGBitmapContextCreate(buffer, brr_app.width, brr_app.height, 8, brr_app.width * BRR_BYTES_PER_PIXEL, colorSpaceRef, kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrder32Little);
    [self setNeedsDisplay:YES];
}


-(void)handleMouseEvent:(NSEvent *)event brrEvent:(brr_event_type)brrEvent brrMouseButton:(brr_mouse_button)mouseButton{
    NSPoint point = [event locationInWindow];
    point = [self convertPoint:point fromView:nil];
    brr_send_mouse_event(brrEvent, mouseButton, [self getModifier:event], point.x, ([self bounds].size.height - point.y));
}

-(void)mouseDown:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEDOWN brrMouseButton:BRR_MOUSE_BUTTON_LEFT];
}

-(void)mouseUp:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEUP brrMouseButton:BRR_MOUSE_BUTTON_LEFT];
}

-(void)rightMouseDown:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEDOWN brrMouseButton:BRR_MOUSE_BUTTON_RIGHT];
}

-(void)rightMouseUp:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEUP brrMouseButton:BRR_MOUSE_BUTTON_RIGHT];
}

-(void)otherMouseDown:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEDOWN brrMouseButton:BRR_MOUSE_BUTTON_OTHER];
}

-(void)otherMouseUp:(NSEvent *)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEUP brrMouseButton:BRR_MOUSE_BUTTON_OTHER];
}

-(void)mouseMoved:(NSEvent*)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEMOVED brrMouseButton:BRR_MOUSE_BUTTON_OTHER];
}

-(void)mouseDragged:(NSEvent*)event{
    [self handleMouseEvent:event brrEvent:BRR_EV_MOUSEMOVED brrMouseButton:BRR_MOUSE_BUTTON_OTHER];
}

- (void)dealloc
{
    [[self timer] invalidate];
    CGColorSpaceRelease(colorSpaceRef);
    CGContextRelease(contextRef);
    free(buffer);
}

- (BOOL)acceptsFirstResponder{
    return YES;
}

- (BOOL)acceptsFirstMouse{
    return YES;
}

- (BOOL)isOpaque {
    return YES;
}

- (BOOL)canBecomeKeyView {
    return YES;
}

- (BOOL)wantsUpdateLayer{
    return YES;
}
@end

void brr_start(const char *window_name, int initial_width, int initial_height, void (*frame_cb)(uint8_t *, int, int), void (*event_cb)(brr_event*)){
    brr_init_app(window_name, initial_width, initial_height, frame_cb, event_cb);
    brr_mac_init_keytable();
    NSApplication *app = [NSApplication sharedApplication];
    BrrAppDelegate *delegate = [[BrrAppDelegate alloc] init];
    [app setDelegate:delegate];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app run];
}

// --------------------------------------------------------------------------------
#elif defined(__linux__) || defined(__unix__)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>

#ifndef BRR_NO_SHARED_MEMORY
#include <X11/extensions/XShm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#endif

#include <stdlib.h> // malloc, free
#include <time.h> // clock_gettime, nanosleep

typedef struct brr_x11_state_t{
    int is_running;
    XEvent event;
    Display *display;
    Window window;
    Visual *visual;
    GC gc;
    int screen;
    int depth;
    Atom wm_delete_window;
    XImage *image;
    uint64_t last_timestamp;
    int key_down[BRR_MAX_KEYCODES];
    int use_shm;
    #ifndef BRR_NO_SHARED_MEMORY
    XShmSegmentInfo shminfo;
    #endif
} brr_x11_state_t;

static brr_x11_state_t brr_x11_state;

static void brr_x11_setup(){
    memset(&brr_x11_state, 0, sizeof(brr_x11_state));

    brr_x11_state.display = XOpenDisplay(NULL);
    if (!brr_x11_state.display){
        abort();
    }
    XkbSetDetectableAutoRepeat(brr_x11_state.display, 1, NULL);
    brr_x11_state.screen = DefaultScreen(brr_x11_state.display);
    brr_x11_state.depth = DefaultDepth(brr_x11_state.display, brr_x11_state.screen);
    brr_x11_state.visual = DefaultVisual(brr_x11_state.display, brr_x11_state.screen);
    if (brr_x11_state.depth < 24) {
        abort(); 
    }
    brr_x11_state.use_shm = 0;
    
    #ifndef BRR_NO_SHARED_MEMORY
    brr_x11_state.use_shm = XShmQueryExtension(brr_x11_state.display);
    #endif
    
    Window root_window = XRootWindow(brr_x11_state.display, brr_x11_state.screen);
    unsigned long attribmask = CWEventMask;
    XSetWindowAttributes attribs;
    attribs.event_mask = KeyPressMask| KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ExposureMask | StructureNotifyMask;
    brr_x11_state.window = XCreateWindow(brr_x11_state.display, root_window, 0, 0, brr_app.width, brr_app.height, 0, brr_x11_state.depth, InputOutput, brr_x11_state.visual, attribmask, &attribs );
    if (!brr_x11_state.window){
        abort();
    }
    XMapWindow(brr_x11_state.display, brr_x11_state.window);
    XStoreName(brr_x11_state.display, brr_x11_state.window, brr_app.window_name);
    brr_x11_state.wm_delete_window = XInternAtom(brr_x11_state.display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(brr_x11_state.display, brr_x11_state.window, &brr_x11_state.wm_delete_window, 1);

    XGCValues xgcvalues;
    int valuemask = GCGraphicsExposures;
    xgcvalues.graphics_exposures = False;
    brr_x11_state.gc = XCreateGC(brr_x11_state.display, brr_x11_state.window, valuemask, &xgcvalues );
}

static void brr_x11_dealloc_image(){
    if (!brr_x11_state.image){
        return;
    }
    if (brr_x11_state.use_shm){
        #ifndef BRR_NO_SHARED_MEMORY
        XSync(brr_x11_state.display, 0);
        XShmDetach (brr_x11_state.display, &brr_x11_state.shminfo);
        XDestroyImage (brr_x11_state.image);
        shmdt (brr_x11_state.shminfo.shmaddr);
        shmctl (brr_x11_state.shminfo.shmid, IPC_RMID, 0);
        #endif
    }else{
        XDestroyImage(brr_x11_state.image);
    }
    brr_x11_state.image = NULL;
}

static void brr_x11_alloc_image(){
    brr_x11_dealloc_image();
    if (brr_x11_state.use_shm){
        #ifndef BRR_NO_SHARED_MEMORY
        brr_x11_state.image = XShmCreateImage(brr_x11_state.display, brr_x11_state.visual, brr_x11_state.depth, ZPixmap, 0, &brr_x11_state.shminfo, brr_app.width, brr_app.height);
        brr_x11_state.shminfo.shmid = shmget (IPC_PRIVATE, brr_x11_state.image->bytes_per_line * brr_x11_state.image->height, IPC_CREAT|0666);
        brr_x11_state.shminfo.shmaddr = brr_x11_state.image->data = shmat (brr_x11_state.shminfo.shmid, 0, 0);
        brr_x11_state.shminfo.readOnly = 0;
        if (!XShmAttach (brr_x11_state.display, &brr_x11_state.shminfo)){
            printf("XShmAttach failed");
            abort();
        };
        #endif
    }else{
        char *buffer = malloc(brr_app.width * brr_app.height * BRR_BYTES_PER_PIXEL);
        brr_x11_state.image = XCreateImage(brr_x11_state.display, brr_x11_state.visual, brr_x11_state.depth, ZPixmap, 0, buffer, brr_app.width, brr_app.height, 32, brr_app.width * BRR_BYTES_PER_PIXEL);
    }
}

static brr_event_modifier brr_x11_get_modifier(uint32_t x11_modifier){
    brr_event_modifier result = 0;
    if (x11_modifier & ShiftMask){
        result |= BRR_MOD_SHIFT;
    }
    if (x11_modifier & ControlMask){
        result |= BRR_MOD_CONTROL;
    }
    if (x11_modifier & Mod1Mask){
        result |= BRR_MOD_ALT;
    }
    if (x11_modifier & Mod4Mask){
        result |= BRR_MOD_SUPER;
    }
    if (x11_modifier & Button1Mask){
        result |= BRR_MOD_MOUSE_LEFT;
    }
    if (x11_modifier & Button2Mask){
        result |= BRR_MOD_MOUSE_MIDDLE;
    }
    if (x11_modifier & Button3Mask){
        result |= BRR_MOD_MOUSE_RIGHT;
    }
    return result;
}

static brr_event_modifier brr_x11_key_to_modifier(brr_keycode keycode){
    switch (keycode){
        case BRR_KEY_LEFT_SHIFT:
        case BRR_KEY_RIGHT_SHIFT:
            return BRR_MOD_SHIFT;
        case BRR_KEY_LEFT_CONTROL:
        case BRR_KEY_RIGHT_CONTROL:
            return BRR_MOD_CONTROL;
        case BRR_KEY_LEFT_ALT:
        case BRR_KEY_RIGHT_ALT:
            return BRR_MOD_ALT;
        case BRR_KEY_LEFT_SUPER:
        case BRR_KEY_RIGHT_SUPER:
            return BRR_MOD_SUPER;
        default:
            break;
    }
    return 0;
}

static brr_mouse_button brr_x11_get_mouse_button(int button){
    switch (button) {
        case Button1:
            return BRR_MOUSE_BUTTON_LEFT;
        case Button2:
            return BRR_MOUSE_BUTTON_MIDDLE;
        case Button3:
            return BRR_MOUSE_BUTTON_RIGHT;
        default:
            break;
    }
    return BRR_MOUSE_BUTTON_OTHER;
}

static brr_event_modifier brr_x11_button_to_modifier(int button){
    switch (button) {
        case Button1:
            return BRR_MOD_MOUSE_LEFT;
        case Button2:
            return BRR_MOD_MOUSE_MIDDLE;
        case Button3:
            return BRR_MOD_MOUSE_RIGHT;
        default:
            break;
    }
    return 0;
}

static void brr_x11_fetch_events(){
    while (XPending(brr_x11_state.display)){
        XNextEvent(brr_x11_state.display, &brr_x11_state.event);
        if (brr_x11_state.event.type == ClientMessage) {
            if ((Atom)brr_x11_state.event.xclient.data.l[0] == brr_x11_state.wm_delete_window) {
                    brr_x11_state.is_running = 0;
            }
        }
        if (brr_x11_state.event.type == ConfigureNotify && (brr_x11_state.event.xconfigure.width != brr_app.width || brr_x11_state.event.xconfigure.height != brr_app.height) ){
            brr_app.width = brr_x11_state.event.xconfigure.width;
            brr_app.height = brr_x11_state.event.xconfigure.height;
            brr_x11_alloc_image();
        }
        if (brr_x11_state.event.type == KeyPress || brr_x11_state.event.type == KeyRelease) {
            brr_keycode keycode = brr_get_keycode(brr_x11_state.event.xkey.keycode);
            brr_event_modifier modifier = brr_x11_get_modifier(brr_x11_state.event.xkey.state);
            brr_event_modifier_flag flag = brr_x11_key_to_modifier(keycode);
            if (brr_x11_state.event.type == KeyPress){
                int repeat = brr_x11_state.key_down[brr_x11_state.event.xkey.keycode];
                modifier |= flag;
                brr_send_key_event(BRR_EV_KEYDOWN, modifier, repeat, keycode);
            }else{
                modifier &= ~flag;
                brr_send_key_event(BRR_EV_KEYUP, modifier, 0, keycode);
            }
            brr_x11_state.key_down[brr_x11_state.event.xkey.keycode] = brr_x11_state.event.type == KeyPress ? 1 : 0;
        }
        if (brr_x11_state.event.type == ButtonPress || brr_x11_state.event.type == ButtonRelease ){
            brr_mouse_button mouse_button = brr_x11_get_mouse_button(brr_x11_state.event.xbutton.button);
            brr_event_modifier modifier = brr_x11_get_modifier(brr_x11_state.event.xbutton.state);
            brr_event_modifier_flag button_flag = brr_x11_button_to_modifier(brr_x11_state.event.xbutton.button);
            if (brr_x11_state.event.type == ButtonPress){
                modifier |= button_flag;
                brr_send_mouse_event(BRR_EV_MOUSEDOWN, mouse_button, modifier, brr_x11_state.event.xbutton.x, brr_x11_state.event.xbutton.y);
            } else{
                modifier &= ~button_flag;
                brr_send_mouse_event(BRR_EV_MOUSEUP, mouse_button, modifier, brr_x11_state.event.xbutton.x, brr_x11_state.event.xbutton.y);
            }
        }
        if (brr_x11_state.event.type == MotionNotify){
            brr_event_modifier modifier = brr_x11_get_modifier(brr_x11_state.event.xmotion.state);
            brr_send_mouse_event(BRR_EV_MOUSEMOVED, BRR_MOUSE_BUTTON_OTHER, modifier, brr_x11_state.event.xmotion.x, brr_x11_state.event.xmotion.y);
        }
    }
}

static void brr_x11_wait_for_expose(){
    int ok = 0;
    while (!ok)
    {
        XNextEvent(brr_x11_state.display, &brr_x11_state.event);
        if (brr_x11_state.event.type == Expose && !brr_x11_state.event.xexpose.count)
        {
            ok = 1;
        }
    }
}

static uint64_t brr_x11_get_time(){
    struct timespec tspec;
    clock_gettime( CLOCK_MONOTONIC, &tspec );
    return (uint64_t)tspec.tv_sec * 1000000000 + (uint64_t)tspec.tv_nsec;
}

void brr_x11_framelock(){
    uint64_t now = brr_x11_get_time();
    if (!brr_x11_state.last_timestamp){
        brr_x11_state.last_timestamp = now;
        return;
    }
    uint64_t elapsed = now - brr_x11_state.last_timestamp;
    uint64_t frame_duration_ns = 1000000000 / BRR_FPS;
    if (elapsed < frame_duration_ns) {
        struct timespec req = {
            .tv_sec = 0,
            .tv_nsec = frame_duration_ns - elapsed
        };
        nanosleep(&req, NULL);
    }
    brr_x11_state.last_timestamp = brr_x11_get_time();
}

// Source: glfw/src/x11_init.c
static int brr_x11_translateKeySyms(const KeySym* keysyms, int width)
{
    if (width > 1)
    {
        switch (keysyms[1])
        {
            case XK_KP_0:           return BRR_KEY_KP_0;
            case XK_KP_1:           return BRR_KEY_KP_1;
            case XK_KP_2:           return BRR_KEY_KP_2;
            case XK_KP_3:           return BRR_KEY_KP_3;
            case XK_KP_4:           return BRR_KEY_KP_4;
            case XK_KP_5:           return BRR_KEY_KP_5;
            case XK_KP_6:           return BRR_KEY_KP_6;
            case XK_KP_7:           return BRR_KEY_KP_7;
            case XK_KP_8:           return BRR_KEY_KP_8;
            case XK_KP_9:           return BRR_KEY_KP_9;
            case XK_KP_Separator:
            case XK_KP_Decimal:     return BRR_KEY_KP_DECIMAL;
            case XK_KP_Equal:       return BRR_KEY_KP_EQUAL;
            case XK_KP_Enter:       return BRR_KEY_KP_ENTER;
            default:                break;
        }
    }

    switch (keysyms[0])
    {
        case XK_Escape:         return BRR_KEY_ESCAPE;
        case XK_Tab:            return BRR_KEY_TAB;
        case XK_Shift_L:        return BRR_KEY_LEFT_SHIFT;
        case XK_Shift_R:        return BRR_KEY_RIGHT_SHIFT;
        case XK_Control_L:      return BRR_KEY_LEFT_CONTROL;
        case XK_Control_R:      return BRR_KEY_RIGHT_CONTROL;
        case XK_Meta_L:
        case XK_Alt_L:          return BRR_KEY_LEFT_ALT;
        case XK_Mode_switch: // Mapped to Alt_R on many keyboards
        case XK_ISO_Level3_Shift: // AltGr on at least some machines
        case XK_Meta_R:
        case XK_Alt_R:          return BRR_KEY_RIGHT_ALT;
        case XK_Super_L:        return BRR_KEY_LEFT_SUPER;
        case XK_Super_R:        return BRR_KEY_RIGHT_SUPER;
        case XK_Menu:           return BRR_KEY_MENU;
        case XK_Num_Lock:       return BRR_KEY_NUM_LOCK;
        case XK_Caps_Lock:      return BRR_KEY_CAPS_LOCK;
        case XK_Print:          return BRR_KEY_PRINT_SCREEN;
        case XK_Scroll_Lock:    return BRR_KEY_SCROLL_LOCK;
        case XK_Pause:          return BRR_KEY_PAUSE;
        case XK_Delete:         return BRR_KEY_DELETE;
        case XK_BackSpace:      return BRR_KEY_BACKSPACE;
        case XK_Return:         return BRR_KEY_ENTER;
        case XK_Home:           return BRR_KEY_HOME;
        case XK_End:            return BRR_KEY_END;
        case XK_Page_Up:        return BRR_KEY_PAGE_UP;
        case XK_Page_Down:      return BRR_KEY_PAGE_DOWN;
        case XK_Insert:         return BRR_KEY_INSERT;
        case XK_Left:           return BRR_KEY_LEFT;
        case XK_Right:          return BRR_KEY_RIGHT;
        case XK_Down:           return BRR_KEY_DOWN;
        case XK_Up:             return BRR_KEY_UP;
        case XK_F1:             return BRR_KEY_F1;
        case XK_F2:             return BRR_KEY_F2;
        case XK_F3:             return BRR_KEY_F3;
        case XK_F4:             return BRR_KEY_F4;
        case XK_F5:             return BRR_KEY_F5;
        case XK_F6:             return BRR_KEY_F6;
        case XK_F7:             return BRR_KEY_F7;
        case XK_F8:             return BRR_KEY_F8;
        case XK_F9:             return BRR_KEY_F9;
        case XK_F10:            return BRR_KEY_F10;
        case XK_F11:            return BRR_KEY_F11;
        case XK_F12:            return BRR_KEY_F12;
        case XK_F13:            return BRR_KEY_F13;
        case XK_F14:            return BRR_KEY_F14;
        case XK_F15:            return BRR_KEY_F15;
        case XK_F16:            return BRR_KEY_F16;
        case XK_F17:            return BRR_KEY_F17;
        case XK_F18:            return BRR_KEY_F18;
        case XK_F19:            return BRR_KEY_F19;
        case XK_F20:            return BRR_KEY_F20;
        case XK_F21:            return BRR_KEY_F21;
        case XK_F22:            return BRR_KEY_F22;
        case XK_F23:            return BRR_KEY_F23;
        case XK_F24:            return BRR_KEY_F24;
        case XK_F25:            return BRR_KEY_F25;

        // Numeric keypad
        case XK_KP_Divide:      return BRR_KEY_KP_DIVIDE;
        case XK_KP_Multiply:    return BRR_KEY_KP_MULTIPLY;
        case XK_KP_Subtract:    return BRR_KEY_KP_SUBTRACT;
        case XK_KP_Add:         return BRR_KEY_KP_ADD;

        // These should have been detected in secondary keysym test above!
        case XK_KP_Insert:      return BRR_KEY_KP_0;
        case XK_KP_End:         return BRR_KEY_KP_1;
        case XK_KP_Down:        return BRR_KEY_KP_2;
        case XK_KP_Page_Down:   return BRR_KEY_KP_3;
        case XK_KP_Left:        return BRR_KEY_KP_4;
        case XK_KP_Right:       return BRR_KEY_KP_6;
        case XK_KP_Home:        return BRR_KEY_KP_7;
        case XK_KP_Up:          return BRR_KEY_KP_8;
        case XK_KP_Page_Up:     return BRR_KEY_KP_9;
        case XK_KP_Delete:      return BRR_KEY_KP_DECIMAL;
        case XK_KP_Equal:       return BRR_KEY_KP_EQUAL;
        case XK_KP_Enter:       return BRR_KEY_KP_ENTER;

        // Last resort: Check for printable keys (should not happen if the XKB
        // extension is available). This will give a layout dependent mapping
        // (which is wrong, and we may miss some keys, especially on non-US
        // keyboards), but it's better than nothing...
        case XK_a:              return BRR_KEY_A;
        case XK_b:              return BRR_KEY_B;
        case XK_c:              return BRR_KEY_C;
        case XK_d:              return BRR_KEY_D;
        case XK_e:              return BRR_KEY_E;
        case XK_f:              return BRR_KEY_F;
        case XK_g:              return BRR_KEY_G;
        case XK_h:              return BRR_KEY_H;
        case XK_i:              return BRR_KEY_I;
        case XK_j:              return BRR_KEY_J;
        case XK_k:              return BRR_KEY_K;
        case XK_l:              return BRR_KEY_L;
        case XK_m:              return BRR_KEY_M;
        case XK_n:              return BRR_KEY_N;
        case XK_o:              return BRR_KEY_O;
        case XK_p:              return BRR_KEY_P;
        case XK_q:              return BRR_KEY_Q;
        case XK_r:              return BRR_KEY_R;
        case XK_s:              return BRR_KEY_S;
        case XK_t:              return BRR_KEY_T;
        case XK_u:              return BRR_KEY_U;
        case XK_v:              return BRR_KEY_V;
        case XK_w:              return BRR_KEY_W;
        case XK_x:              return BRR_KEY_X;
        case XK_y:              return BRR_KEY_Y;
        case XK_z:              return BRR_KEY_Z;
        case XK_1:              return BRR_KEY_1;
        case XK_2:              return BRR_KEY_2;
        case XK_3:              return BRR_KEY_3;
        case XK_4:              return BRR_KEY_4;
        case XK_5:              return BRR_KEY_5;
        case XK_6:              return BRR_KEY_6;
        case XK_7:              return BRR_KEY_7;
        case XK_8:              return BRR_KEY_8;
        case XK_9:              return BRR_KEY_9;
        case XK_0:              return BRR_KEY_0;
        case XK_space:          return BRR_KEY_SPACE;
        case XK_minus:          return BRR_KEY_MINUS;
        case XK_equal:          return BRR_KEY_EQUAL;
        case XK_bracketleft:    return BRR_KEY_LEFT_BRACKET;
        case XK_bracketright:   return BRR_KEY_RIGHT_BRACKET;
        case XK_backslash:      return BRR_KEY_BACKSLASH;
        case XK_semicolon:      return BRR_KEY_SEMICOLON;
        case XK_apostrophe:     return BRR_KEY_APOSTROPHE;
        case XK_grave:          return BRR_KEY_GRAVE_ACCENT;
        case XK_comma:          return BRR_KEY_COMMA;
        case XK_period:         return BRR_KEY_PERIOD;
        case XK_slash:          return BRR_KEY_SLASH;
        case XK_less:           return BRR_KEY_WORLD_1; // At least in some layouts...
        default:                break;
    }

    // No matching translation was found
    return BRR_KEY_UNKNOWN;
}

static void brr_x11_init_keytable(void)
{
    XkbDescPtr desc = XkbGetMap(brr_x11_state.display, 0, XkbUseCoreKbd);
    XkbGetNames(brr_x11_state.display, XkbKeyNamesMask | XkbKeyAliasesMask, desc);
    int scancodeMin = desc->min_key_code;
    int scancodeMax = desc->max_key_code;
    const struct { int key; char* name; } keymap[] =
        {
            { BRR_KEY_GRAVE_ACCENT, "TLDE" },
            { BRR_KEY_1, "AE01" },
            { BRR_KEY_2, "AE02" },
            { BRR_KEY_3, "AE03" },
            { BRR_KEY_4, "AE04" },
            { BRR_KEY_5, "AE05" },
            { BRR_KEY_6, "AE06" },
            { BRR_KEY_7, "AE07" },
            { BRR_KEY_8, "AE08" },
            { BRR_KEY_9, "AE09" },
            { BRR_KEY_0, "AE10" },
            { BRR_KEY_MINUS, "AE11" },
            { BRR_KEY_EQUAL, "AE12" },
            { BRR_KEY_Q, "AD01" },
            { BRR_KEY_W, "AD02" },
            { BRR_KEY_E, "AD03" },
            { BRR_KEY_R, "AD04" },
            { BRR_KEY_T, "AD05" },
            { BRR_KEY_Y, "AD06" },
            { BRR_KEY_U, "AD07" },
            { BRR_KEY_I, "AD08" },
            { BRR_KEY_O, "AD09" },
            { BRR_KEY_P, "AD10" },
            { BRR_KEY_LEFT_BRACKET, "AD11" },
            { BRR_KEY_RIGHT_BRACKET, "AD12" },
            { BRR_KEY_A, "AC01" },
            { BRR_KEY_S, "AC02" },
            { BRR_KEY_D, "AC03" },
            { BRR_KEY_F, "AC04" },
            { BRR_KEY_G, "AC05" },
            { BRR_KEY_H, "AC06" },
            { BRR_KEY_J, "AC07" },
            { BRR_KEY_K, "AC08" },
            { BRR_KEY_L, "AC09" },
            { BRR_KEY_SEMICOLON, "AC10" },
            { BRR_KEY_APOSTROPHE, "AC11" },
            { BRR_KEY_Z, "AB01" },
            { BRR_KEY_X, "AB02" },
            { BRR_KEY_C, "AB03" },
            { BRR_KEY_V, "AB04" },
            { BRR_KEY_B, "AB05" },
            { BRR_KEY_N, "AB06" },
            { BRR_KEY_M, "AB07" },
            { BRR_KEY_COMMA, "AB08" },
            { BRR_KEY_PERIOD, "AB09" },
            { BRR_KEY_SLASH, "AB10" },
            { BRR_KEY_BACKSLASH, "BKSL" },
            { BRR_KEY_WORLD_1, "LSGT" },
            { BRR_KEY_SPACE, "SPCE" },
            { BRR_KEY_ESCAPE, "ESC" },
            { BRR_KEY_ENTER, "RTRN" },
            { BRR_KEY_TAB, "TAB" },
            { BRR_KEY_BACKSPACE, "BKSP" },
            { BRR_KEY_INSERT, "INS" },
            { BRR_KEY_DELETE, "DELE" },
            { BRR_KEY_RIGHT, "RGHT" },
            { BRR_KEY_LEFT, "LEFT" },
            { BRR_KEY_DOWN, "DOWN" },
            { BRR_KEY_UP, "UP" },
            { BRR_KEY_PAGE_UP, "PGUP" },
            { BRR_KEY_PAGE_DOWN, "PGDN" },
            { BRR_KEY_HOME, "HOME" },
            { BRR_KEY_END, "END" },
            { BRR_KEY_CAPS_LOCK, "CAPS" },
            { BRR_KEY_SCROLL_LOCK, "SCLK" },
            { BRR_KEY_NUM_LOCK, "NMLK" },
            { BRR_KEY_PRINT_SCREEN, "PRSC" },
            { BRR_KEY_PAUSE, "PAUS" },
            { BRR_KEY_F1, "FK01" },
            { BRR_KEY_F2, "FK02" },
            { BRR_KEY_F3, "FK03" },
            { BRR_KEY_F4, "FK04" },
            { BRR_KEY_F5, "FK05" },
            { BRR_KEY_F6, "FK06" },
            { BRR_KEY_F7, "FK07" },
            { BRR_KEY_F8, "FK08" },
            { BRR_KEY_F9, "FK09" },
            { BRR_KEY_F10, "FK10" },
            { BRR_KEY_F11, "FK11" },
            { BRR_KEY_F12, "FK12" },
            { BRR_KEY_F13, "FK13" },
            { BRR_KEY_F14, "FK14" },
            { BRR_KEY_F15, "FK15" },
            { BRR_KEY_F16, "FK16" },
            { BRR_KEY_F17, "FK17" },
            { BRR_KEY_F18, "FK18" },
            { BRR_KEY_F19, "FK19" },
            { BRR_KEY_F20, "FK20" },
            { BRR_KEY_F21, "FK21" },
            { BRR_KEY_F22, "FK22" },
            { BRR_KEY_F23, "FK23" },
            { BRR_KEY_F24, "FK24" },
            { BRR_KEY_F25, "FK25" },
            { BRR_KEY_KP_0, "KP0" },
            { BRR_KEY_KP_1, "KP1" },
            { BRR_KEY_KP_2, "KP2" },
            { BRR_KEY_KP_3, "KP3" },
            { BRR_KEY_KP_4, "KP4" },
            { BRR_KEY_KP_5, "KP5" },
            { BRR_KEY_KP_6, "KP6" },
            { BRR_KEY_KP_7, "KP7" },
            { BRR_KEY_KP_8, "KP8" },
            { BRR_KEY_KP_9, "KP9" },
            { BRR_KEY_KP_DECIMAL, "KPDL" },
            { BRR_KEY_KP_DIVIDE, "KPDV" },
            { BRR_KEY_KP_MULTIPLY, "KPMU" },
            { BRR_KEY_KP_SUBTRACT, "KPSU" },
            { BRR_KEY_KP_ADD, "KPAD" },
            { BRR_KEY_KP_ENTER, "KPEN" },
            { BRR_KEY_KP_EQUAL, "KPEQ" },
            { BRR_KEY_LEFT_SHIFT, "LFSH" },
            { BRR_KEY_LEFT_CONTROL, "LCTL" },
            { BRR_KEY_LEFT_ALT, "LALT" },
            { BRR_KEY_LEFT_SUPER, "LWIN" },
            { BRR_KEY_RIGHT_SHIFT, "RTSH" },
            { BRR_KEY_RIGHT_CONTROL, "RCTL" },
            { BRR_KEY_RIGHT_ALT, "RALT" },
            { BRR_KEY_RIGHT_ALT, "LVL3" },
            { BRR_KEY_RIGHT_ALT, "MDSW" },
            { BRR_KEY_RIGHT_SUPER, "RWIN" },
            { BRR_KEY_MENU, "MENU" }
        };
            // Find the X11 key code -> GLFW key code mapping
    for (int scancode = scancodeMin;  scancode <= scancodeMax;  scancode++)
    {
        int key = BRR_KEY_UNKNOWN;

        // Map the key name to a GLFW key code. Note: We use the US
        // keyboard layout. Because function keys aren't mapped correctly
        // when using traditional KeySym translations, they are mapped
        // here instead.
        for (int i = 0;  i < sizeof(keymap) / sizeof(keymap[0]);  i++)
        {
            if (strncmp(desc->names->keys[scancode].name,
                        keymap[i].name,
                        XkbKeyNameLength) == 0)
            {
                key = keymap[i].key;
                break;
            }
        }

        // Fall back to key aliases in case the key name did not match
        for (int i = 0;  i < desc->names->num_key_aliases;  i++)
        {
            if (key != BRR_KEY_UNKNOWN)
                break;

            if (strncmp(desc->names->key_aliases[i].real,
                        desc->names->keys[scancode].name,
                        XkbKeyNameLength) != 0)
            {
                continue;
            }

            for (int j = 0;  j < sizeof(keymap) / sizeof(keymap[0]);  j++)
            {
                if (strncmp(desc->names->key_aliases[i].alias,
                            keymap[j].name,
                            XkbKeyNameLength) == 0)
                {
                    key = keymap[j].key;
                    break;
                }
            }
        }
        brr_app.keycodes[scancode] = key;
    }

    XkbFreeNames(desc, XkbKeyNamesMask, True);
    XkbFreeKeyboard(desc, 0, True);

    int width;
    KeySym* keysyms = XGetKeyboardMapping(brr_x11_state.display,
                                            scancodeMin,
                                            scancodeMax - scancodeMin + 1,
                                            &width);

    for (int scancode = scancodeMin;  scancode <= scancodeMax;  scancode++)
    {
        // Translate the un-translated key codes using traditional X11 KeySym
        // lookups
        if (brr_app.keycodes[scancode] == BRR_KEY_UNKNOWN)
        {
            const size_t base = (scancode - scancodeMin) * width;
            brr_app.keycodes[scancode] = brr_x11_translateKeySyms(&keysyms[base], width);
        }
    }

    XFree(keysyms);
}

void brr_start(const char *window_name, int initial_width, int initial_height, void (*frame_cb)(uint8_t *, int, int), void (*event_cb)(brr_event*)){
    brr_init_app(window_name, initial_width, initial_height, frame_cb, event_cb);
	brr_x11_setup();
    brr_x11_init_keytable();
    brr_x11_alloc_image();
    brr_x11_wait_for_expose();

    brr_x11_state.is_running = 1;
    while (brr_x11_state.is_running) {
        brr_x11_fetch_events();
        if (brr_app.frame_cb){
        	brr_app.frame_cb((uint8_t*)brr_x11_state.image->data, brr_app.width, brr_app.height);
        }
        if (brr_x11_state.use_shm){
            #ifndef BRR_NO_SHARED_MEMORY
            if(!XShmPutImage(brr_x11_state.display, brr_x11_state.window, brr_x11_state.gc, brr_x11_state.image,
                0, 0,
                0, 0,
                brr_app.width, brr_app.height, 0)){
                    printf("XShmPutImage() failed\n");
                    abort();
            };
            #endif
        }else{
            XPutImage(brr_x11_state.display, brr_x11_state.window, brr_x11_state.gc, brr_x11_state.image,
                0, 0,
                0, 0,
                brr_app.width, brr_app.height );
           
        }
        XFlush(brr_x11_state.display);
        brr_x11_framelock();
    }

    brr_x11_dealloc_image();
    XFreeGC(brr_x11_state.display, brr_x11_state.gc);
    XCloseDisplay(brr_x11_state.display);
}

// --------------------------------------------------------------------------------
#elif defined(_WIN32)
#include <windows.h>
#include <windowsx.h>
#pragma comment (lib, "user32")
#pragma comment (lib, "gdi32")
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#pragma comment(linker, "/ENTRY:mainCRTStartup")

typedef struct brr_windows_state_t
{
    int is_running;
    uint8_t *buffer;
    HWND window;
    BITMAPINFO bitmapinfo;
    LARGE_INTEGER freq;
    LARGE_INTEGER last_timestamp;
    WCHAR *window_name_wide;
} brr_windows_state_t;

static brr_windows_state_t brr_windows_state;

static void brr_windows_free_buffer(){
     if (brr_windows_state.buffer){
        free(brr_windows_state.buffer);
        brr_windows_state.buffer = NULL;
    }
}

static void brr_windows_realloc_buffer(){
    brr_windows_free_buffer();
    brr_windows_state.buffer = malloc(brr_app.width * brr_app.height * BRR_BYTES_PER_PIXEL);
}

static void brr_windows_set_dimensions(int width, int height){
    brr_app.width = width;
    brr_app.height = height;
    brr_windows_state.bitmapinfo.bmiHeader.biWidth = width;
    brr_windows_state.bitmapinfo.bmiHeader.biHeight = -height;
    brr_windows_realloc_buffer();
}


static brr_event_modifier brr_windows_get_modifier(){
    brr_event_modifier result = 0;
    if (GetKeyState(VK_SHIFT) & (1<<15)){
        result |= BRR_MOD_SHIFT;
    }
    if (GetKeyState(VK_CONTROL) & (1<<15)){
        result |= BRR_MOD_CONTROL;
    }
    if (GetKeyState(VK_MENU) & (1<<15)){
        result |= BRR_MOD_ALT;
    }
    if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & (1<<15)){
        result |= BRR_MOD_SUPER;
    }

    int swap = GetSystemMetrics( SM_SWAPBUTTON );
    if (GetAsyncKeyState(VK_LBUTTON)) {
        result |= swap ? BRR_MOD_MOUSE_RIGHT : BRR_MOD_MOUSE_LEFT;
    }
    if (GetAsyncKeyState(VK_RBUTTON)) {
        result |= swap ? BRR_MOD_MOUSE_LEFT : BRR_MOD_MOUSE_RIGHT;
    }
    if (GetAsyncKeyState(VK_MBUTTON)) {
        result |= BRR_MOD_MOUSE_MIDDLE;
    }
    return result;
}

// Source: glfw/src/win32_init.c
static void brr_windows_init_keytable(void){
    brr_app.keycodes[0x00B] = BRR_KEY_0;
    brr_app.keycodes[0x002] = BRR_KEY_1;
    brr_app.keycodes[0x003] = BRR_KEY_2;
    brr_app.keycodes[0x004] = BRR_KEY_3;
    brr_app.keycodes[0x005] = BRR_KEY_4;
    brr_app.keycodes[0x006] = BRR_KEY_5;
    brr_app.keycodes[0x007] = BRR_KEY_6;
    brr_app.keycodes[0x008] = BRR_KEY_7;
    brr_app.keycodes[0x009] = BRR_KEY_8;
    brr_app.keycodes[0x00A] = BRR_KEY_9;
    brr_app.keycodes[0x01E] = BRR_KEY_A;
    brr_app.keycodes[0x030] = BRR_KEY_B;
    brr_app.keycodes[0x02E] = BRR_KEY_C;
    brr_app.keycodes[0x020] = BRR_KEY_D;
    brr_app.keycodes[0x012] = BRR_KEY_E;
    brr_app.keycodes[0x021] = BRR_KEY_F;
    brr_app.keycodes[0x022] = BRR_KEY_G;
    brr_app.keycodes[0x023] = BRR_KEY_H;
    brr_app.keycodes[0x017] = BRR_KEY_I;
    brr_app.keycodes[0x024] = BRR_KEY_J;
    brr_app.keycodes[0x025] = BRR_KEY_K;
    brr_app.keycodes[0x026] = BRR_KEY_L;
    brr_app.keycodes[0x032] = BRR_KEY_M;
    brr_app.keycodes[0x031] = BRR_KEY_N;
    brr_app.keycodes[0x018] = BRR_KEY_O;
    brr_app.keycodes[0x019] = BRR_KEY_P;
    brr_app.keycodes[0x010] = BRR_KEY_Q;
    brr_app.keycodes[0x013] = BRR_KEY_R;
    brr_app.keycodes[0x01F] = BRR_KEY_S;
    brr_app.keycodes[0x014] = BRR_KEY_T;
    brr_app.keycodes[0x016] = BRR_KEY_U;
    brr_app.keycodes[0x02F] = BRR_KEY_V;
    brr_app.keycodes[0x011] = BRR_KEY_W;
    brr_app.keycodes[0x02D] = BRR_KEY_X;
    brr_app.keycodes[0x015] = BRR_KEY_Y;
    brr_app.keycodes[0x02C] = BRR_KEY_Z;

    brr_app.keycodes[0x028] = BRR_KEY_APOSTROPHE;
    brr_app.keycodes[0x02B] = BRR_KEY_BACKSLASH;
    brr_app.keycodes[0x033] = BRR_KEY_COMMA;
    brr_app.keycodes[0x00D] = BRR_KEY_EQUAL;
    brr_app.keycodes[0x029] = BRR_KEY_GRAVE_ACCENT;
    brr_app.keycodes[0x01A] = BRR_KEY_LEFT_BRACKET;
    brr_app.keycodes[0x00C] = BRR_KEY_MINUS;
    brr_app.keycodes[0x034] = BRR_KEY_PERIOD;
    brr_app.keycodes[0x01B] = BRR_KEY_RIGHT_BRACKET;
    brr_app.keycodes[0x027] = BRR_KEY_SEMICOLON;
    brr_app.keycodes[0x035] = BRR_KEY_SLASH;
    brr_app.keycodes[0x056] = BRR_KEY_WORLD_2;

    brr_app.keycodes[0x00E] = BRR_KEY_BACKSPACE;
    brr_app.keycodes[0x153] = BRR_KEY_DELETE;
    brr_app.keycodes[0x14F] = BRR_KEY_END;
    brr_app.keycodes[0x01C] = BRR_KEY_ENTER;
    brr_app.keycodes[0x001] = BRR_KEY_ESCAPE;
    brr_app.keycodes[0x147] = BRR_KEY_HOME;
    brr_app.keycodes[0x152] = BRR_KEY_INSERT;
    brr_app.keycodes[0x15D] = BRR_KEY_MENU;
    brr_app.keycodes[0x151] = BRR_KEY_PAGE_DOWN;
    brr_app.keycodes[0x149] = BRR_KEY_PAGE_UP;
    brr_app.keycodes[0x045] = BRR_KEY_PAUSE;
    brr_app.keycodes[0x039] = BRR_KEY_SPACE;
    brr_app.keycodes[0x00F] = BRR_KEY_TAB;
    brr_app.keycodes[0x03A] = BRR_KEY_CAPS_LOCK;
    brr_app.keycodes[0x145] = BRR_KEY_NUM_LOCK;
    brr_app.keycodes[0x046] = BRR_KEY_SCROLL_LOCK;
    brr_app.keycodes[0x03B] = BRR_KEY_F1;
    brr_app.keycodes[0x03C] = BRR_KEY_F2;
    brr_app.keycodes[0x03D] = BRR_KEY_F3;
    brr_app.keycodes[0x03E] = BRR_KEY_F4;
    brr_app.keycodes[0x03F] = BRR_KEY_F5;
    brr_app.keycodes[0x040] = BRR_KEY_F6;
    brr_app.keycodes[0x041] = BRR_KEY_F7;
    brr_app.keycodes[0x042] = BRR_KEY_F8;
    brr_app.keycodes[0x043] = BRR_KEY_F9;
    brr_app.keycodes[0x044] = BRR_KEY_F10;
    brr_app.keycodes[0x057] = BRR_KEY_F11;
    brr_app.keycodes[0x058] = BRR_KEY_F12;
    brr_app.keycodes[0x064] = BRR_KEY_F13;
    brr_app.keycodes[0x065] = BRR_KEY_F14;
    brr_app.keycodes[0x066] = BRR_KEY_F15;
    brr_app.keycodes[0x067] = BRR_KEY_F16;
    brr_app.keycodes[0x068] = BRR_KEY_F17;
    brr_app.keycodes[0x069] = BRR_KEY_F18;
    brr_app.keycodes[0x06A] = BRR_KEY_F19;
    brr_app.keycodes[0x06B] = BRR_KEY_F20;
    brr_app.keycodes[0x06C] = BRR_KEY_F21;
    brr_app.keycodes[0x06D] = BRR_KEY_F22;
    brr_app.keycodes[0x06E] = BRR_KEY_F23;
    brr_app.keycodes[0x076] = BRR_KEY_F24;
    brr_app.keycodes[0x038] = BRR_KEY_LEFT_ALT;
    brr_app.keycodes[0x01D] = BRR_KEY_LEFT_CONTROL;
    brr_app.keycodes[0x02A] = BRR_KEY_LEFT_SHIFT;
    brr_app.keycodes[0x15B] = BRR_KEY_LEFT_SUPER;
    brr_app.keycodes[0x137] = BRR_KEY_PRINT_SCREEN;
    brr_app.keycodes[0x138] = BRR_KEY_RIGHT_ALT;
    brr_app.keycodes[0x11D] = BRR_KEY_RIGHT_CONTROL;
    brr_app.keycodes[0x036] = BRR_KEY_RIGHT_SHIFT;
    brr_app.keycodes[0x15C] = BRR_KEY_RIGHT_SUPER;
    brr_app.keycodes[0x150] = BRR_KEY_DOWN;
    brr_app.keycodes[0x14B] = BRR_KEY_LEFT;
    brr_app.keycodes[0x14D] = BRR_KEY_RIGHT;
    brr_app.keycodes[0x148] = BRR_KEY_UP;

    brr_app.keycodes[0x052] = BRR_KEY_KP_0;
    brr_app.keycodes[0x04F] = BRR_KEY_KP_1;
    brr_app.keycodes[0x050] = BRR_KEY_KP_2;
    brr_app.keycodes[0x051] = BRR_KEY_KP_3;
    brr_app.keycodes[0x04B] = BRR_KEY_KP_4;
    brr_app.keycodes[0x04C] = BRR_KEY_KP_5;
    brr_app.keycodes[0x04D] = BRR_KEY_KP_6;
    brr_app.keycodes[0x047] = BRR_KEY_KP_7;
    brr_app.keycodes[0x048] = BRR_KEY_KP_8;
    brr_app.keycodes[0x049] = BRR_KEY_KP_9;
    brr_app.keycodes[0x04E] = BRR_KEY_KP_ADD;
    brr_app.keycodes[0x053] = BRR_KEY_KP_DECIMAL;
    brr_app.keycodes[0x135] = BRR_KEY_KP_DIVIDE;
    brr_app.keycodes[0x11C] = BRR_KEY_KP_ENTER;
    brr_app.keycodes[0x059] = BRR_KEY_KP_EQUAL;
    brr_app.keycodes[0x037] = BRR_KEY_KP_MULTIPLY;
    brr_app.keycodes[0x04A] = BRR_KEY_KP_SUBTRACT;
}

WCHAR *brr_windows_convert_to_wchar(const char *input) {
    int len = MultiByteToWideChar(CP_UTF8, 0, input, -1, NULL, 0);
    if (len == 0) return NULL;
    WCHAR *output = (WCHAR *)malloc(len * sizeof(WCHAR));
    MultiByteToWideChar(CP_UTF8, 0, input, -1, output, len);
    return output;
}

static void brr_windows_setup(){
    memset(&brr_windows_state, 0, sizeof(brr_windows_state));
    brr_windows_state.window_name_wide = brr_windows_convert_to_wchar(brr_app.window_name);
    brr_windows_state.bitmapinfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    brr_windows_state.bitmapinfo.bmiHeader.biBitCount = 32;
    brr_windows_state.bitmapinfo.bmiHeader.biPlanes = 1;
    brr_windows_state.bitmapinfo.bmiHeader.biCompression = BI_RGB;
    brr_windows_set_dimensions(brr_app.width, brr_app.height);
    QueryPerformanceFrequency(&brr_windows_state.freq);
}

static void brr_windows_handle_mouse_event(brr_event_type ev_type, brr_mouse_button mouse_button, LPARAM lParam){
    const float x = (float)GET_X_LPARAM(lParam);
    const float y = (float)GET_Y_LPARAM(lParam);
    brr_send_mouse_event(ev_type, mouse_button, brr_windows_get_modifier(), x, y);
}

LRESULT CALLBACK brr_windows_winproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC device_context = BeginPaint(hwnd, &ps);
        StretchDIBits(
                device_context,
                0, 0, brr_app.width, brr_app.height,
                0, 0, brr_app.width, brr_app.height,
                brr_windows_state.buffer,
                &brr_windows_state.bitmapinfo,
                DIB_RGB_COLORS,
                SRCCOPY
        );
        EndPaint(hwnd, &ps);
        return 0;
    case WM_SIZE:
        UINT width = LOWORD(lParam);
        UINT height = HIWORD(lParam);
        if (width != brr_app.width || height != brr_app.height){
            brr_windows_set_dimensions(width, height);
        }
        return 0;
    case WM_CLOSE:
        brr_windows_state.is_running = 0;
        return 0;
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYUP:
    case WM_SYSKEYDOWN:
        WORD keyFlags = HIWORD(lParam);
        int scancode = (keyFlags & (KF_EXTENDED | 0xff));
        BOOL isKeyReleased = (keyFlags & KF_UP) == KF_UP;
        BOOL isRepeat = (lParam & (1 << 30)) != 0;
        
        brr_send_key_event(isKeyReleased ? BRR_EV_KEYUP : BRR_EV_KEYDOWN, brr_windows_get_modifier(), isRepeat ? 1 : 0, brr_get_keycode(scancode));
        return 0;
    case WM_LBUTTONUP:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEUP, BRR_MOUSE_BUTTON_LEFT, lParam);
        return 0;
    case WM_RBUTTONUP:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEUP, BRR_MOUSE_BUTTON_RIGHT, lParam);
        return 0;
    case WM_MBUTTONUP:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEUP, BRR_MOUSE_BUTTON_MIDDLE, lParam);
        return 0;
    case WM_LBUTTONDOWN:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEDOWN, BRR_MOUSE_BUTTON_LEFT, lParam);
        return 0;
    case WM_RBUTTONDOWN:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEDOWN, BRR_MOUSE_BUTTON_RIGHT, lParam);
        return 0;
    case WM_MBUTTONDOWN:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEDOWN, BRR_MOUSE_BUTTON_MIDDLE, lParam);
        return 0;
    case WM_MOUSEMOVE:
        brr_windows_handle_mouse_event(BRR_EV_MOUSEMOVED, BRR_MOUSE_BUTTON_OTHER, lParam);
        return 0;
    default:
        break;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

const wchar_t win_class_name[] = L"BRRWINDOWCLASS";

static void brr_windows_create_window(){
    WNDCLASSW wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = brr_windows_winproc;
    wc.hInstance = GetModuleHandleW(NULL);
    wc.lpszClassName = win_class_name;

    RegisterClassW(&wc); 
    brr_windows_state.window = CreateWindowExW(
        0,
        win_class_name,
        brr_windows_state.window_name_wide,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, brr_app.width, brr_app.height,
        NULL, NULL, GetModuleHandleW(NULL), NULL
    );

    if (!brr_windows_state.window) return;
    ShowWindow(brr_windows_state.window, SW_SHOW);
}

static void brr_windows_destroy_window(){
    DestroyWindow(brr_windows_state.window); 
    brr_windows_state.window = 0;
    UnregisterClassW(win_class_name, GetModuleHandleW(NULL));
}

static void brr_windows_framelock(){
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    if (brr_windows_state.last_timestamp.QuadPart == 0){
        brr_windows_state.last_timestamp = now;
        return;
    }
    double elapsed = (double)(now.QuadPart - brr_windows_state.last_timestamp.QuadPart) / brr_windows_state.freq.QuadPart;
    double frame_duration = 1.0 / BRR_FPS;
    if (elapsed < frame_duration) {
        Sleep((frame_duration - elapsed) * 1000);
    }
    QueryPerformanceCounter(&brr_windows_state.last_timestamp);
}

void brr_start(const char *window_name, int initial_width, int initial_height, void (*frame_cb)(uint8_t *, int, int), void (*event_cb)(brr_event*)){
    brr_init_app(window_name, initial_width, initial_height, frame_cb, event_cb);
	brr_windows_init_keytable();
    brr_windows_setup();
    brr_windows_create_window();
    brr_windows_state.is_running = 1;

    while (brr_windows_state.is_running)
    {
        MSG msg;
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT){
                brr_windows_state.is_running = 0;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        if (brr_app.frame_cb){
            brr_app.frame_cb(brr_windows_state.buffer, brr_app.width, brr_app.height);
        }

        InvalidateRect(brr_windows_state.window, NULL, FALSE);
        UpdateWindow(brr_windows_state.window); 

        brr_windows_framelock();
    }

    brr_windows_destroy_window();
    brr_windows_free_buffer();
    free(brr_windows_state.window_name_wide);
}

#endif
#endif