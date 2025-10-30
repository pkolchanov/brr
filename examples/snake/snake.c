#include <stdio.h>
#define BRR_IMPLEMENTATION
#include "../../brr.h"

#define CELL_SIZE 10
#define GRID_WIDTH 32
#define GRID_HEIGHT 20

#define MAX_SNAKE_LEN (GRID_WIDTH * GRID_HEIGHT)

typedef struct {
  int x, y;
} Point2D;

static Point2D snake[MAX_SNAKE_LEN];
static int snake_len = 3;
static Point2D dir = {1, 0};
static Point2D food;
static int game_over = 0;
static int tick = 0;
static brr_event last_event;

static void spawn_food() {
  int valid = 0;
  Point2D candidate = {0, 0};
  while (!valid) {
    candidate.x = rand() % GRID_WIDTH;
    candidate.y = rand() % GRID_HEIGHT;
    valid = 1;
    for (int i = 0; i < snake_len; i++) {
      if (snake[i].x == candidate.x && snake[i].y == candidate.y) {
        valid = 0;
        break;
      }
    }
  }
  food = candidate;
}

static void reset_game() {
  snake_len = 3;
  dir.x = 1;
  dir.y = 0;
  for (int i = 0; i < snake_len; i++) {
    snake[i].x = GRID_WIDTH / 2 - i;
    snake[i].y = GRID_HEIGHT / 2;
  }
  spawn_food();
  game_over = 0;
}

static void handle_keys() {
  if (last_event.event_type == BRR_EV_KEYDOWN) {
    switch (last_event.keycode) {
    case BRR_KEY_UP:
      if (dir.y == 0) {
        dir.x = 0;
        dir.y = -1;
      }
      break;
    case BRR_KEY_DOWN:
      if (dir.y == 0) {
        dir.x = 0;
        dir.y = 1;
      }
      break;
    case BRR_KEY_LEFT:
      if (dir.x == 0) {
        dir.x = -1;
        dir.y = 0;
      }
      break;
    case BRR_KEY_RIGHT:
      if (dir.x == 0) {
        dir.x = 1;
        dir.y = 0;
      }
      break;
    case BRR_KEY_SPACE:
      reset_game();
      break;
    default:
      break;
    }
  }
}

static void update() {
  Point2D new_head = {snake[0].x + dir.x, snake[0].y + dir.y};

  if (new_head.x < 0 || new_head.y < 0 || new_head.x >= GRID_WIDTH ||
      new_head.y >= GRID_HEIGHT) {
    game_over = 1;
    return;
  }

  for (int i = 0; i < snake_len; i++) {
    if (snake[i].x == new_head.x && snake[i].y == new_head.y) {
      game_over = 1;
      return;
    }
  }

  for (int i = snake_len; i > 0; i--) {
    snake[i] = snake[i - 1];
  }
  snake[0] = new_head;

  if (new_head.x == food.x && new_head.y == food.y) {
    snake_len++;
    spawn_food();
  }
}

static void frame(uint8_t *buffer, int width, int height) {
  handle_keys();

  memset(buffer, 0, width * height * BRR_BYTES_PER_PIXEL);

  if (game_over) {
    for (int i = 0; i < width * height * BRR_BYTES_PER_PIXEL;
         i += BRR_BYTES_PER_PIXEL) {
      buffer[i + 2] = 128;
    }
    return;
  }

  if (++tick % 10 == 0) { // such a robust solution!
    update();
  }

  for (int py = 0; py < CELL_SIZE; py++) {
    for (int px = 0; px < CELL_SIZE; px++) {
      int sx = (food.x * CELL_SIZE + px);
      int sy = (food.y * CELL_SIZE + py);
      int idx = (sy * width + sx) * BRR_BYTES_PER_PIXEL;
      buffer[idx] = 0;
      buffer[idx + 1] = 0;
      buffer[idx + 2] = 255;
    }
  }

  for (int i = 0; i < snake_len; i++) {
    for (int py = 0; py < CELL_SIZE; py++) {
      for (int px = 0; px < CELL_SIZE; px++) {
        int sx = (snake[i].x * CELL_SIZE + px);
        int sy = (snake[i].y * CELL_SIZE + py);
        if (sx < 0 || sy < 0 || sx >= width || sy >= height)
          continue;
        int idx = (sy * width + sx) * BRR_BYTES_PER_PIXEL;
        buffer[idx] = 0;
        buffer[idx + 1] = 255;
        buffer[idx + 2] = 0;
      }
    }
  }
}

void event(brr_event *e) { last_event = *e; }

int main(int argc, const char *argv[]) {
  brr_start("brr snake", 320, 200, frame, event, NULL);
}
