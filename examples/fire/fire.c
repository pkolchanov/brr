#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define BRR_IMPLEMENTATION
#include "../../brr.h"

#define FIRE_WIDTH 320
#define FIRE_HEIGHT 200

typedef struct {
  int h; // 0..360
  int s; // 0..255
  int l; // 0..255
} ColorHSL;

typedef struct {
  uint8_t r, g, b;
} ColorRGB;


static uint8_t fire[FIRE_HEIGHT][FIRE_WIDTH];
static ColorRGB palette[256];

static float clamp01(float v) {
  if (v < 0.0f)
    return 0.0f;
  if (v > 1.0f)
    return 1.0f;
  return v;
}

static float hue2rgb(float p, float q, float t) {
  while (t < 0.0f)
    t += 1.0f;
  while (t > 1.0f)
    t -= 1.0f;
  if (t < 1.0f / 6.0f)
    return p + (q - p) * 6.0f * t;
  if (t < 1.0f / 2.0f)
    return q;
  if (t < 2.0f / 3.0f)
    return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
  return p;
}

static ColorRGB HSLtoRGB(ColorHSL in) {
  float h = (float)in.h;
  float s = (float)in.s / 255.0f;
  float l = (float)in.l / 255.0f;

  ColorRGB out;
  if (in.s == 0) {
    uint8_t v = (uint8_t)(l * 255.0f + 0.5f);
    out.r = out.g = out.b = v;
    return out;
  }

  while (h < 0.0f)
    h += 360.0f;
  while (h >= 360.0f)
    h -= 360.0f;
  float hn = h / 360.0f;

  float q = (l < 0.5f) ? (l * (1.0f + s)) : (l + s - l * s);
  float p = 2.0f * l - q;

  float rf = hue2rgb(p, q, hn + 1.0f / 3.0f);
  float gf = hue2rgb(p, q, hn);
  float bf = hue2rgb(p, q, hn - 1.0f / 3.0f);

  out.r = (uint8_t)(clamp01(rf) * 255.0f + 0.5f);
  out.g = (uint8_t)(clamp01(gf) * 255.0f + 0.5f);
  out.b = (uint8_t)(clamp01(bf) * 255.0f + 0.5f);
  return out;
}

static void generate_fire_palette(ColorRGB out_palette[256]) {
  for (int x = 0; x < 256; ++x) {
    // Hue: 0..85 (red -> yellow), Saturation: 255,
    // Lightness: min(255, x*2)
    int h = x / 3; // 0..85
    int s = 255;
    int l = (x * 2 < 255) ? (x * 2) : 255;

    ColorHSL hsl = (ColorHSL){h, s, l};
    out_palette[x] = HSLtoRGB(hsl);
  }
}


static void frame(uint8_t *buffer, int width, int height) {
  const int fw = FIRE_WIDTH;
  const int fh = FIRE_HEIGHT;

  for (int x = 0; x < fw; ++x) {
    fire[fh - 1][x] = (uint8_t)(rand() & 0xFF);
  }

  for (int y = 0; y < fh - 1; ++y) {
    int y1 = (y + 1) % fh;
    int y2 = (y + 2) % fh;
    for (int x = 0; x < fw; ++x) {
      int xm = (x - 1 + fw) % fw;
      int xp = (x + 1) % fw;

      int v = fire[y1][xm] + fire[y1][x] + fire[y1][xp] + fire[y2][x];
      fire[y][x] = (uint8_t)((v * 32) / 129);
    }
  }

  for (int y = 0; y < height; ++y) {
    int fy = y % fh;
    for (int x = 0; x < width; ++x) {
      int fx = x % fw;

      const ColorRGB c = palette[fire[fy][fx]];
      int idx = (y * width + x) * BRR_BYTES_PER_PIXEL;

      buffer[idx] = c.b;
      buffer[idx + 1] = c.g;
      buffer[idx + 2] = c.r;
    }
  }
}

int main(void) {
  srand((unsigned)time(NULL));
  generate_fire_palette(palette);

  const int win_w = 960;
  const int win_h = 200;

  brr_start("brr fire", 320, 200, frame, NULL, NULL);
  return 0;
}
