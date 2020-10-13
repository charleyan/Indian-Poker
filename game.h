#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Game {
public:
  Game();

  void collect_cardNum();

  void collect_names();

  void set_win_condition();

  // Set players array with Player objects.
  // Shuffles the deck and deals to each Player.
  // Sorts the Player vector according to their cards, in order to determine
  // the correct ranking.
  void pregame();

  void set_cardNum(unsigned int cardNum_in);

  // TODO: Iterate through Players turns vector and request
  // all players to print which position they believe they are in.
  void round_one();

  void round_two();

  void restart_game();

  void end_game();

  void show_players(unsigned int current);

  void play_game();

  bool get_play_condition();

  void flip_play_condition();

private:
  bool play_condition;
  unsigned int cardNum;
  Deck deck;
  int players_num;
  vector<string> names;
  vector<Player> turns;
  vector<Player> order;
  vector<bool> win_condition;
};

#endif
