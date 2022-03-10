// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 31/07/15

// .h file to store new functions written for main_bot.c not in trader_bot.h

#include "trader_bot.h"

int nearest_seller(struct bot *b);
int nearest_buyer(struct bot *b);
int nearest_dump(struct bot *b);
int nearest_demand(struct bot *b);
int world_distance(struct bot *b);
int total_buyers(struct bot *b);
int total_sellers(struct bot *b);
int last(struct bot *b);
int stranded(struct bot *b, int nextMove);

int calculate_profit(struct bot *b, struct commodity *commodity, int buyPrice, int sellPrice, int buyQuantity, int sellQuantity);
char *profit_buyer(struct bot *b);
char *profit_seller(struct bot *b);
int shortest_distance(struct bot *b, char *locationName);
int moves_profits(struct bot *b, char *sellerName, int localProfit);
