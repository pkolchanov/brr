#ifndef BRR_INCL
#define BRR_INCL

#include "stdint.h"
#define BYTES_PER_PIXEL 4

void brr_start(void);

typedef enum brr_event_type{
    BRR_EV_KEYDOWN,
    BRR_EV_KEYUP
} brr_event_type;

// Source: GLFW keycodes
typedef enum brr_keycode{
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

#define MAX_KEYCODES 512

typedef struct brr_app {
    void (*frame)(uint8_t *, int, int);
    void (*event)(brr_event);
    int width;
    int height;
    brr_keycode keycodes[MAX_KEYCODES];
} brr_app;

extern brr_app _app;
#endif


#ifdef BRR_IMPLEMENTATION
//todo Place?
brr_app _app = {0, 0, 320, 200};

#if defined(__APPLE__) && 0
#import <Cocoa/Cocoa.h>

static void init_keytable(void)
{
    memset(_app.keycodes, -1, sizeof(_app.keycodes));

    _app.keycodes[0x1D] = BRR_KEY_0;
    _app.keycodes[0x12] = BRR_KEY_1;
    _app.keycodes[0x13] = BRR_KEY_2;
    _app.keycodes[0x14] = BRR_KEY_3;
    _app.keycodes[0x15] = BRR_KEY_4;
    _app.keycodes[0x17] = BRR_KEY_5;
    _app.keycodes[0x16] = BRR_KEY_6;
    _app.keycodes[0x1A] = BRR_KEY_7;
    _app.keycodes[0x1C] = BRR_KEY_8;
    _app.keycodes[0x19] = BRR_KEY_9;
    _app.keycodes[0x00] = BRR_KEY_A;
    _app.keycodes[0x0B] = BRR_KEY_B;
    _app.keycodes[0x08] = BRR_KEY_C;
    _app.keycodes[0x02] = BRR_KEY_D;
    _app.keycodes[0x0E] = BRR_KEY_E;
    _app.keycodes[0x03] = BRR_KEY_F;
    _app.keycodes[0x05] = BRR_KEY_G;
    _app.keycodes[0x04] = BRR_KEY_H;
    _app.keycodes[0x22] = BRR_KEY_I;
    _app.keycodes[0x26] = BRR_KEY_J;
    _app.keycodes[0x28] = BRR_KEY_K;
    _app.keycodes[0x25] = BRR_KEY_L;
    _app.keycodes[0x2E] = BRR_KEY_M;
    _app.keycodes[0x2D] = BRR_KEY_N;
    _app.keycodes[0x1F] = BRR_KEY_O;
    _app.keycodes[0x23] = BRR_KEY_P;
    _app.keycodes[0x0C] = BRR_KEY_Q;
    _app.keycodes[0x0F] = BRR_KEY_R;
    _app.keycodes[0x01] = BRR_KEY_S;
    _app.keycodes[0x11] = BRR_KEY_T;
    _app.keycodes[0x20] = BRR_KEY_U;
    _app.keycodes[0x09] = BRR_KEY_V;
    _app.keycodes[0x0D] = BRR_KEY_W;
    _app.keycodes[0x07] = BRR_KEY_X;
    _app.keycodes[0x10] = BRR_KEY_Y;
    _app.keycodes[0x06] = BRR_KEY_Z;

    _app.keycodes[0x27] = BRR_KEY_APOSTROPHE;
    _app.keycodes[0x2A] = BRR_KEY_BACKSLASH;
    _app.keycodes[0x2B] = BRR_KEY_COMMA;
    _app.keycodes[0x18] = BRR_KEY_EQUAL;
    _app.keycodes[0x32] = BRR_KEY_GRAVE_ACCENT;
    _app.keycodes[0x21] = BRR_KEY_LEFT_BRACKET;
    _app.keycodes[0x1B] = BRR_KEY_MINUS;
    _app.keycodes[0x2F] = BRR_KEY_PERIOD;
    _app.keycodes[0x1E] = BRR_KEY_RIGHT_BRACKET;
    _app.keycodes[0x29] = BRR_KEY_SEMICOLON;
    _app.keycodes[0x2C] = BRR_KEY_SLASH;
    _app.keycodes[0x0A] = BRR_KEY_WORLD_1;

    _app.keycodes[0x33] = BRR_KEY_BACKSPACE;
    _app.keycodes[0x39] = BRR_KEY_CAPS_LOCK;
    _app.keycodes[0x75] = BRR_KEY_DELETE;
    _app.keycodes[0x7D] = BRR_KEY_DOWN;
    _app.keycodes[0x77] = BRR_KEY_END;
    _app.keycodes[0x24] = BRR_KEY_ENTER;
    _app.keycodes[0x35] = BRR_KEY_ESCAPE;
    _app.keycodes[0x7A] = BRR_KEY_F1;
    _app.keycodes[0x78] = BRR_KEY_F2;
    _app.keycodes[0x63] = BRR_KEY_F3;
    _app.keycodes[0x76] = BRR_KEY_F4;
    _app.keycodes[0x60] = BRR_KEY_F5;
    _app.keycodes[0x61] = BRR_KEY_F6;
    _app.keycodes[0x62] = BRR_KEY_F7;
    _app.keycodes[0x64] = BRR_KEY_F8;
    _app.keycodes[0x65] = BRR_KEY_F9;
    _app.keycodes[0x6D] = BRR_KEY_F10;
    _app.keycodes[0x67] = BRR_KEY_F11;
    _app.keycodes[0x6F] = BRR_KEY_F12;
    _app.keycodes[0x69] = BRR_KEY_PRINT_SCREEN;
    _app.keycodes[0x6B] = BRR_KEY_F14;
    _app.keycodes[0x71] = BRR_KEY_F15;
    _app.keycodes[0x6A] = BRR_KEY_F16;
    _app.keycodes[0x40] = BRR_KEY_F17;
    _app.keycodes[0x4F] = BRR_KEY_F18;
    _app.keycodes[0x50] = BRR_KEY_F19;
    _app.keycodes[0x5A] = BRR_KEY_F20;
    _app.keycodes[0x73] = BRR_KEY_HOME;
    _app.keycodes[0x72] = BRR_KEY_INSERT;
    _app.keycodes[0x7B] = BRR_KEY_LEFT;
    _app.keycodes[0x3A] = BRR_KEY_LEFT_ALT;
    _app.keycodes[0x3B] = BRR_KEY_LEFT_CONTROL;
    _app.keycodes[0x38] = BRR_KEY_LEFT_SHIFT;
    _app.keycodes[0x37] = BRR_KEY_LEFT_SUPER;
    _app.keycodes[0x6E] = BRR_KEY_MENU;
    _app.keycodes[0x47] = BRR_KEY_NUM_LOCK;
    _app.keycodes[0x79] = BRR_KEY_PAGE_DOWN;
    _app.keycodes[0x74] = BRR_KEY_PAGE_UP;
    _app.keycodes[0x7C] = BRR_KEY_RIGHT;
    _app.keycodes[0x3D] = BRR_KEY_RIGHT_ALT;
    _app.keycodes[0x3E] = BRR_KEY_RIGHT_CONTROL;
    _app.keycodes[0x3C] = BRR_KEY_RIGHT_SHIFT;
    _app.keycodes[0x36] = BRR_KEY_RIGHT_SUPER;
    _app.keycodes[0x31] = BRR_KEY_SPACE;
    _app.keycodes[0x30] = BRR_KEY_TAB;
    _app.keycodes[0x7E] = BRR_KEY_UP;

    _app.keycodes[0x52] = BRR_KEY_KP_0;
    _app.keycodes[0x53] = BRR_KEY_KP_1;
    _app.keycodes[0x54] = BRR_KEY_KP_2;
    _app.keycodes[0x55] = BRR_KEY_KP_3;
    _app.keycodes[0x56] = BRR_KEY_KP_4;
    _app.keycodes[0x57] = BRR_KEY_KP_5;
    _app.keycodes[0x58] = BRR_KEY_KP_6;
    _app.keycodes[0x59] = BRR_KEY_KP_7;
    _app.keycodes[0x5B] = BRR_KEY_KP_8;
    _app.keycodes[0x5C] = BRR_KEY_KP_9;
    _app.keycodes[0x45] = BRR_KEY_KP_ADD;
    _app.keycodes[0x41] = BRR_KEY_KP_DECIMAL;
    _app.keycodes[0x4B] = BRR_KEY_KP_DIVIDE;
    _app.keycodes[0x4C] = BRR_KEY_KP_ENTER;
    _app.keycodes[0x51] = BRR_KEY_KP_EQUAL;
    _app.keycodes[0x43] = BRR_KEY_KP_MULTIPLY;
    _app.keycodes[0x4E] = BRR_KEY_KP_SUBTRACT;
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
    window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, _app.width, _app.height)
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
    [NSTimer scheduledTimerWithTimeInterval: 1/30.0
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
    if (_app.event){
        _app.event((brr_event){BRR_EV_KEYDOWN, _app.keycodes[event.keyCode]});
    }
}

- (void)keyUp:(NSEvent *)event{
    if (_app.event){
        _app.event((brr_event){BRR_EV_KEYUP, _app.keycodes[event.keyCode]});
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
    if (keyCode > 0 && _app.event) {
        brr_event ev;
        ev.event_type = down ? BRR_EV_KEYDOWN : BRR_EV_KEYUP;
        ev.keycode = keyCode;
        _app.event(ev);
    }
    oldFlags = [event modifierFlags];
}

- (void)drawRect:(NSRect)dirtyRect{
    if (_app.frame) {
        _app.frame(buffer, _app.width, _app.height);
    }
    CGImageRef image = CGBitmapContextCreateImage(contextRef);
    CGContextRef ctx = [NSGraphicsContext currentContext].CGContext;
    CGContextDrawImage(ctx, dirtyRect, image);
    CGImageRelease(image);
}

- (void)setFrameSize:(NSSize)newSize{
    _app.width = newSize.width;
    _app.height = newSize.height;
    [self reallocBuffer];
}

-(void)reallocBuffer{
    if (buffer){
        CGContextRelease(contextRef);
        free(buffer);
        buffer = NULL;
    }
    size_t bitmapSize = sizeof(uint8_t) * _app.width * BYTES_PER_PIXEL * _app.height;
    buffer = malloc(bitmapSize);
    contextRef = CGBitmapContextCreate(buffer, _app.width, _app.height, 8, _app.width * BYTES_PER_PIXEL, colorSpaceRef, kCGImageAlphaNoneSkipLast);
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
#include <stdio.h>  // printf
#include <stdint.h> // uint8_t, uint32_t
#include <stdlib.h> // malloc, free
#include <string.h> // memset
#include <time.h> // clock_gettime, nanosleep

// static int width = 1240;
// static int height = 800;
static int bpp = 4;
static int fps = 30;

typedef struct x11_state_desc{
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
} x11_state_desc;

static x11_state_desc x11_state;

int x11_get_shift_of_mask(unsigned long mask){
    int shift = 0;
    if (mask == 0) return shift;
    while ((mask & 1) == 0 && shift < sizeof(unsigned long) * 8)
    {
        mask >>= 1;
        shift++;
    }
    return shift;
}

void x11_create_lut(){
    int red_shift = x11_get_shift_of_mask(x11_state.visual->red_mask);
    int green_shift = x11_get_shift_of_mask(x11_state.visual->green_mask);
    int blue_shift = x11_get_shift_of_mask(x11_state.visual->blue_mask);

    for (int i = 0; i< 256; i++){
        x11_state.lut_red[i] = i << red_shift;
        x11_state.lut_green[i] = i << green_shift;
        x11_state.lut_blue[i] = i << blue_shift;
    }
}

void x11_swizzle_rgbx(){
    uint8_t *from = x11_state.data;
    uint32_t *to = (uint32_t *) x11_state.imgdata;
    for (int i = 0; i < _app.width * _app.height; i += 1){
        int idx = i * bpp;
        to[i] = x11_state.lut_red[from[idx]] |
            x11_state.lut_green[from[idx + 1]] |
            x11_state.lut_blue[from[idx + 2]];
    }
}


void x11_setup(){
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
    x11_state.window = XCreateWindow(x11_state.display, root_window, 0, 0, _app.width, _app.height, 0, x11_state.depth, InputOutput, x11_state.visual, attribmask, &attribs );
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


void x11_alloc_image(){
    if (x11_state.image){
        XDestroyImage(x11_state.image);
        x11_state.image = NULL;
        x11_state.imgdata = NULL;
    }
     if (x11_state.data){
        free(x11_state.data);
        x11_state.data = NULL;
    }

    x11_state.data = malloc(_app.width * _app.height * bpp);
    x11_state.imgdata = malloc(_app.width * _app.height * bpp);
    x11_state.image = XCreateImage(x11_state.display, x11_state.visual, x11_state.depth, ZPixmap, 0, x11_state.imgdata, _app.width, _app.height, 32, _app.width*bpp);
}

void x11_dealloc_image(){
    XDestroyImage(x11_state.image);
    free(x11_state.data);
}

void x11_fetch_events(){
    while (XPending(x11_state.display)){
        XNextEvent(x11_state.display, &x11_state.event);
        if (x11_state.event.type == ClientMessage) {
            if ((Atom)x11_state.event.xclient.data.l[0] == x11_state.wm_delete_window) {
                    x11_state.is_running = 0;
            }
        }
        if (x11_state.event.type == ConfigureNotify && (x11_state.event.xconfigure.width != _app.width || x11_state.event.xconfigure.height != _app.height) ){
            _app.width = x11_state.event.xconfigure.width;
            _app.height = x11_state.event.xconfigure.height;
            x11_alloc_image();
        }
        printf("%d\n",x11_state.event.type);
    }
}


void x11_wait_for_expose(){
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

uint64_t x11_get_time(){
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
    uint64_t frame_duration_ns = 1000000000 / fps;
    if (elapsed < frame_duration_ns) {
        struct timespec req = {
            .tv_sec = 0,
            .tv_nsec = frame_duration_ns - elapsed
        };
        nanosleep(&req, NULL);
    }
    x11_state.last_timestamp = x11_get_time();
}

void brr_start(void){
	x11_setup();
    x11_create_lut();
    x11_alloc_image();
    x11_wait_for_expose();

    x11_state.is_running = 1;
    while (x11_state.is_running) {
        x11_fetch_events();
        if (_app.frame){
        	_app.frame(x11_state.data, _app.width, _app.height);
        }
        x11_swizzle_rgbx();
        XPutImage(x11_state.display, x11_state.window, x11_state.gc, x11_state.image,
			0, 0,
			0, 0,
			_app.width, _app.height );
        XFlush(x11_state.display);
        x11_framelock();
    }

    x11_dealloc_image();
    XFreeGC(x11_state.display, x11_state.gc);
    XCloseDisplay(x11_state.display);
}
#endif
#endif
