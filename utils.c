#include "utils.h"
#include <math.h>
#include <stdlib.h>

#define MAP_EDGE_SIZE 401

double distance(int x_1, int y_1, int x_2, int y_2) {
  int diff_x = abs(x_1 - x_2);
  int w_diff_x = MAP_EDGE_SIZE - diff_x;
  int diff_y = abs(y_1 - y_2);
  int w_diff_y = MAP_EDGE_SIZE - diff_y;

  int final_diff_x = diff_x < w_diff_x ? diff_x : w_diff_x;
  int final_diff_y = diff_y < w_diff_y ? diff_y : w_diff_y;

  return pow(final_diff_x, 2) + pow(final_diff_y, 2);
}
