#include "trade_route.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>




trade_route* generate_trade_routes(village village, unsigned int n_time_ticks) {

  const trade_route default_tr = {
    .enable_route = 0,
    .time_tick = 0,
    .destination_village = 0,
    .clay_amount = 0,
    .iron_amount = 0,
    .wood_amount = 0,
    .cereal_amount = 0,

  };

  trade_route* p_tr =  (trade_route*) malloc(sizeof(trade_route) * n_time_ticks);

  if(p_tr) {
    for(int i=0; i < n_time_ticks; i++){
      p_tr[i] = default_tr;
      p_tr[i].time_tick = i;
    }
  }

  return p_tr;
}

void print_trade_route(trade_route tr) {
    printf("trade_route ->\n \
	   enable: %u\n \
	   tick: %u\n \
	   destination_village: %u\n \
	   clay_amount: %u\n \
	   iron_amount: %u\n \
	   wood_amount: %u\n \
	   cereal_amount: %u\n",
	   tr.enable_route,
	   tr.time_tick,
	   tr.destination_village,
	   tr.clay_amount,
	   tr.iron_amount,
	   tr.wood_amount,
	   tr.cereal_amount);
}


trade_route_bits trb_from_params(village village, uint n_villages) {
  const size_t bits_enable_route = 1;
  uint max_capacity = village.marketplace_level * 500;
  size_t bits_max_capacity = (size_t) ceil(sqrt(max_capacity));
  size_t bits_n_villages = (size_t) ceil(sqrt(n_villages));
  size_t total_bits = bits_enable_route + bits_n_villages + bits_max_capacity * 4;

  return (trade_route_bits) {
    .bits_enable_route=bits_enable_route,
    .bits_n_villages=bits_n_villages,
    .bits_max_capacity=bits_max_capacity,
    .total_bits=total_bits,
  };
}

size_t bytes_required_for_trb(trade_route_bits trb) {
  return ceil(trb.total_bits * 1.0 / 8.0);
}



trade_route_bits bits_required(village village, uint n_time_ticks, uint n_villages) {
  const size_t bits_enable_route = 1;
  uint max_capacity = village.marketplace_level * 500;
  size_t bits_max_capacity = (size_t) ceil(sqrt(max_capacity));
  size_t bits_n_villages = (size_t) ceil(sqrt(n_villages));
  size_t total_bits = bits_enable_route + bits_n_villages + bits_max_capacity * 4;

  return (trade_route_bits) {
    .bits_enable_route=bits_enable_route,
    .bits_n_villages=bits_n_villages,
    .bits_max_capacity=bits_max_capacity,
    .total_bits=total_bits,
  };
}

size_t bytes_required(size_t n_bits) {
  return ceil(n_bits*1.0 / 8.0);
}

size_t bits_leftover(size_t n_bits, size_t n_bytes) {
  size_t leftover = n_bits % n_bytes;
  assert(leftover <= 7);
  return leftover;
}

char* generate_village_chromosome(village village, uint n_time_ticks, uint n_villages) {
  trade_route_bits tr_bits = bits_required(village, n_time_ticks, n_villages);
  char* p = (char*) malloc(bytes_required(tr_bits.total_bits) * n_time_ticks);
  return p;
}

