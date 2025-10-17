#define BRR_IMPLEMENTATION
#include "../../brr.h"
#include "doomgeneric/doomgeneric.h"
#include "doomgeneric/doomkeys.h"
#include <time.h>

#define KEYQUEUE_SIZE 16

static unsigned short s_KeyQueue[KEYQUEUE_SIZE];
static unsigned int s_KeyQueueWriteIndex = 0;
static unsigned int s_KeyQueueReadIndex = 0;

void DG_DrawFrame()
{
}

void DG_Init()
{
}

void DG_SetWindowTitle(const char *title)
{
}

static unsigned char convertToDoomKey(unsigned int key)
{
    switch (key)
    {
    case BRR_KEY_ENTER:
        key = KEY_ENTER;
        break;
    case BRR_KEY_ESCAPE:
        key = KEY_ESCAPE;
        break;
    case BRR_KEY_LEFT:
        key = KEY_LEFTARROW;
        break;
    case BRR_KEY_RIGHT:
        key = KEY_RIGHTARROW;
        break;
    case BRR_KEY_UP:
        key = KEY_UPARROW;
        break;
    case BRR_KEY_DOWN:
        key = KEY_DOWNARROW;
        break;
    case BRR_KEY_LEFT_CONTROL:
    case BRR_KEY_RIGHT_CONTROL:
        key = KEY_FIRE;
        break;
    case BRR_KEY_SPACE:
        key = KEY_USE;
        break;
    case BRR_KEY_LEFT_SHIFT:
    case BRR_KEY_RIGHT_SHIFT:
        key = KEY_RSHIFT;
        break;
    case BRR_KEY_LEFT_ALT:
    case BRR_KEY_RIGHT_ALT:
        key = KEY_LALT;
        break;
    case BRR_KEY_F2:
        key = KEY_F2;
        break;
    case BRR_KEY_F3:
        key = KEY_F3;
        break;
    case BRR_KEY_F4:
        key = KEY_F4;
        break;
    case BRR_KEY_F5:
        key = KEY_F5;
        break;
    case BRR_KEY_F6:
        key = KEY_F6;
        break;
    case BRR_KEY_F7:
        key = KEY_F7;
        break;
    case BRR_KEY_F8:
        key = KEY_F8;
        break;
    case BRR_KEY_F9:
        key = KEY_F9;
        break;
    case BRR_KEY_F10:
        key = KEY_F10;
        break;
    case BRR_KEY_F11:
        key = KEY_F11;
        break;
    case BRR_KEY_EQUAL:
        key = KEY_EQUALS;
        break;
    case BRR_KEY_MINUS:
        key = KEY_MINUS;
        break;
    case BRR_KEY_BACKSPACE:
        key = KEY_BACKSPACE;
        break;
    default:
        key = tolower(key);
        break;
    }

    return key;
}

static void addKeyToQueue(int pressed, unsigned int keyCode)
{
    unsigned char key = convertToDoomKey(keyCode);

    unsigned short keyData = (pressed << 8) | key;

    s_KeyQueue[s_KeyQueueWriteIndex] = keyData;
    s_KeyQueueWriteIndex++;
    s_KeyQueueWriteIndex %= KEYQUEUE_SIZE;
}

#ifdef _WIN32
#include <windows.h>

void DG_SleepMs(uint32_t ms)
{
    Sleep(ms);
}

uint32_t DG_GetTicksMs()
{
    return (uint32_t)GetTickCount64();
}

#else
#include <unistd.h>
#include <time.h>

void DG_SleepMs(uint32_t ms)
{
    usleep(ms * 1000);
}

uint32_t DG_GetTicksMs()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)((ts.tv_sec * 1000UL) + (ts.tv_nsec / 1000000UL));
}

#endif

int DG_GetKey(int *pressed, unsigned char *doomKey)
{
    if (s_KeyQueueReadIndex == s_KeyQueueWriteIndex)
    {
        // key queue is empty
        return 0;
    }
    else
    {
        unsigned short keyData = s_KeyQueue[s_KeyQueueReadIndex];
        s_KeyQueueReadIndex++;
        s_KeyQueueReadIndex %= KEYQUEUE_SIZE;

        *pressed = keyData >> 8;
        *doomKey = keyData & 0xFF;

        return 1;
    }

    return 0;
}

// ------------------------------------------------------------

void frame(uint8_t *buffer, int width, int height){
    uint32_t *dst = (uint32_t *)buffer;
    doomgeneric_Tick();
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int src_x = x * DOOMGENERIC_RESX / width;
            int src_y = y * DOOMGENERIC_RESY / height;
            int src_idx = src_y * DOOMGENERIC_RESX + src_x;
            int dst_idx = y * width + x;
            dst[dst_idx] = DG_ScreenBuffer[src_idx];
        }
    }
}

void event(brr_event *event){
    if (event->event_type == BRR_EV_KEYDOWN)
    {
        addKeyToQueue(1, event->keycode);
    }
    if (event->event_type == BRR_EV_KEYUP)
    {
        addKeyToQueue(0, event->keycode);
    }
}

int main(int argc, const char *argv[]){
    doomgeneric_Create(argc, argv);
    brr_start("brr doom", 320, 200, frame, event, NULL);
}