#include "ga.h"
#include "trade_route.h"
#include <stdlib.h>
#include <stdio.h>


trade_route initialize_trade_route(trade_route default_tr, village village, unsigned int n_villages) {
  uint capacity_by_merchant = 500;
  uint max_capacity = village.marketplace_level * capacity_by_merchant;
  default_tr.enable_route = rand_range(2);
  default_tr.destination_village = rand_range(n_villages);
  default_tr.clay_amount = rand_range(max_capacity+1);
  default_tr.iron_amount = rand_range(max_capacity+1);
  default_tr.wood_amount = rand_range(max_capacity+1);
  default_tr.cereal_amount = rand_range(max_capacity+1);
  return default_tr;
}

uint rand_range(uint max_number) {
    int limit;
    int r;

    limit = RAND_MAX - (RAND_MAX % max_number);

    while((r = rand()) >= limit);

    return r % max_number;
}
