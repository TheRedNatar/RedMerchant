#ifndef TRADE_ROUTE_H
#define TRADE_ROUTE_H

#include "utils.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct village {
  int x;
  int y;
  tribe_t tribe;
  unsigned int village_id;
  uint marketplace_level;
  unsigned int materials_storage;
  unsigned int cereal_storage;
  unsigned int clay_production;
  unsigned int iron_production;
  unsigned int wood_production;
  int cereal_production;
} village;

typedef struct trade_route {
  bool enable_route;
  unsigned int time_tick;
  unsigned int destination_village;
  unsigned int clay_amount;
  unsigned int iron_amount;
  unsigned int wood_amount;
  unsigned int cereal_amount;
} trade_route;


typedef struct trade_route_bits {
  size_t bits_enable_route;
  size_t bits_n_villages;
  size_t bits_max_capacity;
  size_t total_bits;
} trade_route_bits;

trade_route_bits trb_from_params(village village, uint n_villages);
size_t bytes_required_for_trb(trade_route_bits trb);
trade_route tr_from_bytes(char* tr_bytes, trade_route_bits trb, unsigned int time_tick);


trade_route* generate_trade_routes(village village, unsigned int n_time_ticks);
void print_trade_route(trade_route tr);
trade_route_bits bits_required(village village, uint n_time_ticks, uint n_villages);
size_t bytes_required(size_t n_bits);
size_t bits_leftover(size_t n_bits, size_t n_bytes);
char* generate_village_chromosome(village village, uint n_time_ticks, uint n_villages);

#endif
