#ifndef CARD_H
#define CARD_H

#include <unordered_map>
#include <vector>
#include <string>

using std::unordered_map;
using std::vector;
using std::string;

extern unordered_map<unsigned int, string> value_to_cardface;

vector<string> cardface{
  "Two",
  "Three",
  "Four",
  "Five",
  "Six",
  "Seven",
  "Eight",
  "Nine",
  "Ten",
  "Jack",
  "Queen",
  "King",
  "Ace",
  "Small Joker",
  "Big Joker",
  "Indian"
};

struct Card {
  unsigned int trueValue;
  string facade;

  Card() {
    trueValue = 0;
    facade = "";
  }

  Card(unsigned int value)
  {
    trueValue = value;
    facade = value_to_cardface[trueValue];
  }

  bool operator < (const Card & c2) const
  {
    return trueValue < c2.trueValue;
  }

};

void define_map();

#endif
