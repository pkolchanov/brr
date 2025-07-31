#ifndef BRR_INCL
#define BRR_INCL
#include "stdint.h"
#define BYTES_PER_PIXEL 4
#define FPS 30
#define MAX_KEYCODES 512

void brr_start(void);

typedef enum brr_event_type{
    BRR_EV_KEYDOWN,
    BRR_EV_KEYUP
} brr_event_type;

// Source: GLFW keycodes
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
    int keycode;
} brr_event;

typedef struct brr_app_t {
    void (*frame)(uint8_t *, int, int);
    void (*event)(brr_event);
    int width;
    int height;
    brr_keycode keycodes[MAX_KEYCODES];
} brr_app_t;

extern brr_app_t brr_app;
#endif


#ifdef BRR_IMPLEMENTATION
//todo Place?
brr_app_t brr_app = {0, 0, 320, 200};

#if defined(__APPLE__) && 0
#import <Cocoa/Cocoa.h>

static void init_keytable(void)
{
    memset(brr_app.keycodes, -1, sizeof(brr_app.keycodes));

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


@interface AppDelegate : NSObject <NSApplicationDelegate>{
    NSWindow *window;
}
@end

@interface BRRView : NSView{
    NSEventModifierFlags oldFlags;
    CGContextRef contextRef;
    CGColorSpaceRef colorSpaceRef;
    uint8_t *buffer;
}
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, brr_app.width, brr_app.height)
                                         styleMask:(NSWindowStyleMaskTitled |
                                                    NSWindowStyleMaskClosable |
                                                    NSWindowStyleMaskResizable)
                                           backing:NSBackingStoreBuffered
                                             defer:NO];

    BRRView *view = [[BRRView alloc] init];
    [window setContentView:view];
    [window setTitle:@"BRR"];
    [window makeKeyAndOrderFront:nil];
    // todo CADisplayLink or CVDisplayLink
    [NSTimer scheduledTimerWithTimeInterval: 1.0/FPS
                          target: self
                          selector:@selector(onTick:)
                          userInfo: nil repeats:YES];
}

-(void)onTick:(NSTimer *)timer {
    [[window contentView] setNeedsDisplay:YES];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}

@end

@implementation BRRView
- (instancetype)init
{
    self = [super init];
    if (self) {
        colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    }
    return self;
}


- (void)keyDown:(NSEvent *)event{
    if (brr_app.event){
        brr_app.event((brr_event){BRR_EV_KEYDOWN, brr_app.keycodes[event.keyCode]});
    }
}

- (void)keyUp:(NSEvent *)event{
    if (brr_app.event){
        brr_app.event((brr_event){BRR_EV_KEYUP, brr_app.keycodes[event.keyCode]});
    }
}

- (void)flagsChanged:(NSEvent *)event {
    Boolean down = NO;
    int keyCode = -1;
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
    if (keyCode > 0 && brr_app.event) {
        brr_event ev;
        ev.event_type = down ? BRR_EV_KEYDOWN : BRR_EV_KEYUP;
        ev.keycode = keyCode;
        brr_app.event(ev);
    }
    oldFlags = [event modifierFlags];
}

- (void)drawRect:(NSRect)dirtyRect{
    if (brr_app.frame) {
        brr_app.frame(buffer, brr_app.width, brr_app.height);
    }
    CGImageRef image = CGBitmapContextCreateImage(contextRef);
    CGContextRef ctx = [NSGraphicsContext currentContext].CGContext;
    CGContextDrawImage(ctx, dirtyRect, image);
    CGImageRelease(image);
}

- (void)setFrameSize:(NSSize)newSize{
    brr_app.width = newSize.width;
    brr_app.height = newSize.height;
    [self reallocBuffer];
}

-(void)reallocBuffer{
    if (buffer){
        CGContextRelease(contextRef);
        free(buffer);
        buffer = NULL;
    }
    size_t bitmapSize = sizeof(uint8_t) * brr_app.width * BYTES_PER_PIXEL * brr_app.height;
    buffer = malloc(bitmapSize);
    contextRef = CGBitmapContextCreate(buffer, brr_app.width, brr_app.height, 8, brr_app.width * BYTES_PER_PIXEL, colorSpaceRef, kCGImageAlphaNoneSkipLast);
    [self setNeedsDisplay:YES];
}

- (void)dealloc
{
    CGColorSpaceRelease(colorSpaceRef);
    CGContextRelease(contextRef);
    free(buffer);
}

- (BOOL)acceptsFirstResponder{
    return YES;
}
@end

void brr_start(void){
    init_keytable();
    NSApplication *app = [NSApplication sharedApplication];
    AppDelegate *delegate = [[AppDelegate alloc] init];
    [app setDelegate:delegate];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app run];
}

#elif defined(__linux__) || defined(__unix__) || 1
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <stdio.h>  // printf
#include <stdint.h> // uint8_t, uint32_t
#include <stdlib.h> // malloc, free
#include <string.h> // memset
#include <time.h> // clock_gettime, nanosleep

typedef struct x11_state_t{
    int is_running;
    XEvent event;
    Display *display;
    Window window;
    Visual *visual;
    GC gc;
    int screen;
    int depth;
    Atom wm_delete_window;
    uint8_t *data;
    uint8_t *imgdata;
    XImage *image;
    uint64_t last_timestamp;
    uint32_t lut_red[256];
    uint32_t lut_green[256];
    uint32_t lut_blue[256];
} x11_state_t;

static x11_state_t x11_state;

static int x11_get_shift_of_mask(unsigned long mask){
    int shift = 0;
    if (mask == 0) return shift;
    while ((mask & 1) == 0 && shift < sizeof(unsigned long) * 8)
    {
        mask >>= 1;
        shift++;
    }
    return shift;
}

static void x11_create_lut(){
    int red_shift = x11_get_shift_of_mask(x11_state.visual->red_mask);
    int green_shift = x11_get_shift_of_mask(x11_state.visual->green_mask);
    int blue_shift = x11_get_shift_of_mask(x11_state.visual->blue_mask);

    for (int i = 0; i< 256; i++){
        x11_state.lut_red[i] = i << red_shift;
        x11_state.lut_green[i] = i << green_shift;
        x11_state.lut_blue[i] = i << blue_shift;
    }
}

static void x11_swizzle_rgbx(){
    uint8_t *from = x11_state.data;
    uint32_t *to = (uint32_t *) x11_state.imgdata;
    for (int i = 0; i < brr_app.width * brr_app.height; i += 1){
        int idx = i * BYTES_PER_PIXEL;
        to[i] = x11_state.lut_red[from[idx]] |
            x11_state.lut_green[from[idx + 1]] |
            x11_state.lut_blue[from[idx + 2]];
    }
}

static void x11_setup(){
    memset(&x11_state, 0, sizeof(x11_state));

    x11_state.display = XOpenDisplay(NULL);
    if (!x11_state.display){
        abort();
    }
    x11_state.screen = DefaultScreen(x11_state.display);
    x11_state.depth =  DefaultDepth(x11_state.display, x11_state.screen);
    x11_state.visual = DefaultVisual(x11_state.display, x11_state.screen);

    Window root_window = XRootWindow(x11_state.display, x11_state.screen);
    unsigned long attribmask = CWEventMask;
    XSetWindowAttributes attribs;
    attribs.event_mask = KeyPressMask| KeyReleaseMask | ExposureMask | StructureNotifyMask;
    x11_state.window = XCreateWindow(x11_state.display, root_window, 0, 0, brr_app.width, brr_app.height, 0, x11_state.depth, InputOutput, x11_state.visual, attribmask, &attribs );
    if (!x11_state.window){
        abort();
    }
    XMapWindow(x11_state.display, x11_state.window);
    x11_state.wm_delete_window = XInternAtom(x11_state.display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(x11_state.display, x11_state.window, &x11_state.wm_delete_window, 1);

    XGCValues xgcvalues;
    int valuemask = GCGraphicsExposures;
    xgcvalues.graphics_exposures = False;
    x11_state.gc = XCreateGC(x11_state.display, x11_state.window, valuemask, &xgcvalues );
}

static void x11_alloc_image(){
    if (x11_state.image){
        XDestroyImage(x11_state.image);
        x11_state.image = NULL;
        x11_state.imgdata = NULL;
    }
     if (x11_state.data){
        free(x11_state.data);
        x11_state.data = NULL;
    }

    x11_state.data = malloc(brr_app.width * brr_app.height * BYTES_PER_PIXEL);
    x11_state.imgdata = malloc(brr_app.width * brr_app.height * BYTES_PER_PIXEL);
    x11_state.image = XCreateImage(x11_state.display, x11_state.visual, x11_state.depth, ZPixmap, 0, x11_state.imgdata, brr_app.width, brr_app.height, 32, brr_app.width * BYTES_PER_PIXEL);
}

static void x11_dealloc_image(){
    XDestroyImage(x11_state.image);
    free(x11_state.data);
}

static void x11_fetch_events(){
    while (XPending(x11_state.display)){
        XNextEvent(x11_state.display, &x11_state.event);
        if (x11_state.event.type == ClientMessage) {
            if ((Atom)x11_state.event.xclient.data.l[0] == x11_state.wm_delete_window) {
                    x11_state.is_running = 0;
            }
        }
        if (x11_state.event.type == ConfigureNotify && (x11_state.event.xconfigure.width != brr_app.width || x11_state.event.xconfigure.height != brr_app.height) ){
            brr_app.width = x11_state.event.xconfigure.width;
            brr_app.height = x11_state.event.xconfigure.height;
            x11_alloc_image();
        }
        if (x11_state.event.type == KeyPress || x11_state.event.type == KeyRelease) {
            if (brr_app.event){
                brr_event event;
                event.event_type = x11_state.event.type == KeyPress ? BRR_EV_KEYDOWN : BRR_EV_KEYUP;
                event.keycode = brr_app.keycodes[x11_state.event.xkey.keycode];
                brr_app.event(event);
            }
        }
    }
}

static void x11_wait_for_expose(){
    int ok = 0;
    while (!ok)
    {
        XNextEvent(x11_state.display, &x11_state.event);
        if (x11_state.event.type == Expose && !x11_state.event.xexpose.count)
        {
            ok = 1;
        }
    }
}

static uint64_t x11_get_time(){
    struct timespec tspec;
    clock_gettime( CLOCK_MONOTONIC, &tspec );
    return (uint64_t)tspec.tv_sec*1000000000 + (uint64_t)tspec.tv_nsec;
}

void x11_framelock(){
    uint64_t now = x11_get_time();
    if (!x11_state.last_timestamp){
        x11_state.last_timestamp = now;
        return;
    }
    uint64_t elapsed = now - x11_state.last_timestamp;
    uint64_t frame_duration_ns = 1000000000 / FPS;
    if (elapsed < frame_duration_ns) {
        struct timespec req = {
            .tv_sec = 0,
            .tv_nsec = frame_duration_ns - elapsed
        };
        nanosleep(&req, NULL);
    }
    x11_state.last_timestamp = x11_get_time();
}

// Translate the X11 KeySyms for a key to a GLFW key code
// NOTE: This is only used as a fallback, in case the XKB method fails
//       It is layout-dependent and will fail partially on most non-US layouts
//
static int translateKeySyms(const KeySym* keysyms, int width)
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

static void x11_init_keytable(void)
{
	// source: GLFW
    memset(brr_app.keycodes, -1, sizeof(brr_app.keycodes));
    XkbDescPtr desc = XkbGetMap(x11_state.display, 0, XkbUseCoreKbd);
    XkbGetNames(x11_state.display, XkbKeyNamesMask | XkbKeyAliasesMask, desc);
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
    KeySym* keysyms = XGetKeyboardMapping(x11_state.display,
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
            brr_app.keycodes[scancode] = translateKeySyms(&keysyms[base], width);
        }
    }

    XFree(keysyms);
}

void brr_start(void){
	x11_setup();
    x11_create_lut();
    x11_init_keytable();
    x11_alloc_image();
    x11_wait_for_expose();

    x11_state.is_running = 1;
    while (x11_state.is_running) {
        x11_fetch_events();
        if (brr_app.frame){
        	brr_app.frame(x11_state.data, brr_app.width, brr_app.height);
        }
        x11_swizzle_rgbx();
        XPutImage(x11_state.display, x11_state.window, x11_state.gc, x11_state.image,
			0, 0,
			0, 0,
			brr_app.width, brr_app.height );
        XFlush(x11_state.display);
        x11_framelock();
    }

    x11_dealloc_image();
    XFreeGC(x11_state.display, x11_state.gc);
    XCloseDisplay(x11_state.display);
}
#endif
#endif
