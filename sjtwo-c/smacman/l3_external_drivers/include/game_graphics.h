#pragma once
#include "FreeRTOS.h"
#include "led_graphics.h"
#include "led_matrix.h"

typedef struct {
  int8_t row;
  int8_t col;
  uint8_t vx;
  uint8_t vy;
  int8_t xDir;
  int8_t yDir;
} ball_s;

typedef struct {
  int row_upordown_right;
  int row_upordown_left;
  int row_left_upordown;
  int row_right_upordown;
  int col_up_leftorright;
  int col_down_leftorright;
  int col_leftorrigt_up;
  int col_leftorrigt_down;
  led_matrix__color_e packman_color;
  led_matrix__direction_e direction;
} pacman_s;

typedef enum { PLAYER_1 = 1, PLAYER_2 } game_graphics_players;

static uint8_t player_1_packman_row, player_1_packman_col;
static uint8_t player_2_packman_row, player_2_packman_col;
void increase_ball_x(ball_s *ball);
void decrease_ball_x(ball_s *ball);
void ball_setup(ball_s *ball);
void blue_pacman_setup(pacman_s *blue_pacman);
void green_pacman_setup(void);
void clear_ball(int row, int column);

void set_pacman_row_and_col(int row, int col, game_graphics_players which_player);

void detect_collision(ball_s ball);

void game_graphics_packman(int row, int column, led_matrix__direction_e direction, led_matrix__color_e packman_color,
                           game_graphics_players which_player);