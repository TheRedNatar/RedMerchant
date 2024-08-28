#ifndef GA_H
#define GA_H

#include "trade_route.h"

trade_route initialize_trade_route(trade_route default_tr, village village, unsigned int n_villages);
uint rand_range(uint max_number);

#endif
