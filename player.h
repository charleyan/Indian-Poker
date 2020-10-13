#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <string>

using std::string;

class Player {
public:
  Player(string name_in, unsigned int turn_in);

  void set_card(Card card_in);

  void set_turn(unsigned int turn_in);

  void set_order(unsigned int order_in);

  Card& get_card();

  void set_guess(unsigned int guess_in);

  string get_name();

  bool check_guess();

private:
  Card card;
  string name;
  unsigned int turn;
  unsigned int order;
  unsigned int guess;
};

struct PlayerComparator {
  bool operator () (Player & p1, Player & p2) {
    return p1.get_card() < p2.get_card();
  }
};

#endif
