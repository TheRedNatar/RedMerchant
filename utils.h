#ifndef UTILS_H
#define UTILS_H

typedef enum tribe {ROMANS, TEUTONS, GAULS, NATURE, NATARS, EGYPTIANS, HUNS, SPARTANS} tribe_t;

struct village {
  int x;
  int y;
  tribe_t tribe;
  unsigned int village_id;
  unsigned int marketplace_level;
  unsigned int materials_storage;
  unsigned int cereal_storage;
  unsigned int clay_production;
  unsigned int iron_production;
  unsigned int wood_production;
  int cereal_production;
};

double distance(int x_1, int y_1, int x_2, int y_2);

#endif
