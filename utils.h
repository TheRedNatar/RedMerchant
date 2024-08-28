#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef enum tribe {ROMANS, TEUTONS, GAULS, NATURE, NATARS, EGYPTIANS, HUNS, SPARTANS} tribe_t;

double distance(int x_1, int y_1, int x_2, int y_2);


typedef struct extra_config {
  uint n_time_ticks;
  uint n_villages;

} extra_config;

#endif
