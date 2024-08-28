#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#include "ga.h"
#include "trade_route.h"
#include "utils.h"


int main(int argc, char *argv[]) {
  double dis = distance(1, 1, 22, 1);
  printf("Hello, World! -> %f\n", dis);


  const village v = {
    .x = 0,
    .y = 0,
    .tribe = ROMANS,
    .village_id = 0,
    .marketplace_level = 1,
    .materials_storage = 0,
    .cereal_storage = 0,
    .clay_production = 0,
    .iron_production = 0,
    .wood_production = 0,
    .cereal_production = 0
  };

  extra_config config = {
    .n_time_ticks = 7,
    .n_villages = 1
  };

  srand(time(NULL));

  trade_route_bits trb = trb_from_params(v, config.n_villages);
  size_t total_bytes = bytes_required_for_trb(trb);
  char* chromosome = (char*) malloc(total_bytes * config.n_time_ticks);

  assert(chromosome != NULL);

  for(int i=0; i<config.n_villages; i++) {
    size_t village_offset = i * total_bytes; //need to change
    for(int j=0; i<config.n_time_ticks; j++) {
      trade_route tr = tr_from_bytes(&chromosome[village_offset + j], trb, config.n_time_ticks);
      print_trade_route(tr);
      }
  }


  trade_route* routes = generate_trade_routes(v, config.n_time_ticks);

  for(int i=0; i<config.n_time_ticks; i++) {
    routes[i] = initialize_trade_route(routes[i], v, config.n_villages);
    print_trade_route(routes[i]);
  }
   
  return 0;
}


