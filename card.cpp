/* card.cpp
  Implmentation of declard functions in card.h
  May 2020
  Charles Yan
*/

#include "card.h"

#include <unordered_map>

using std::unordered_map;

void define_map() {
  value_to_cardface[2] = "Two";
  value_to_cardface[3] = "Three";
  value_to_cardface[4] = "Four";
  value_to_cardface[5] = "Five";
  value_to_cardface[6] = "Six";
  value_to_cardface[7] = "Seven";
  value_to_cardface[8] = "Eight";
  value_to_cardface[9] = "Nine";
  value_to_cardface[10] = "Ten";
  value_to_cardface[11] = "Jack";
  value_to_cardface[12] = "Queen";
  value_to_cardface[13] = "King";
  value_to_cardface[14] = "Ace";
  value_to_cardface[15] = "Small Joker";
  value_to_cardface[16] = "Big Joker";
  value_to_cardface[17] = "Indian";
  return;
}
