/* game.cpp
  Implmentation of game.h
*/

#include "game.h"

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::to_string;
using std::vector;

Game::Game() {
  collect_cardNum();

  collect_names();

  set_win_condition();

  for (unsigned int i = 0; i < names.size(); ++i) {
    turns.push_back(Player(names[i], (i+1)));
  }

  deck = Deck(cardNum);

  play_condition = true;
}

void Game::collect_cardNum()
{
  cout << "Enter the number of cards: ";
  cin >> cardNum;
}

void Game::collect_names()
{
  int playerNum = 0;

  cout << "Enter the number of players: ";
  cin >> playerNum;

  for (int i = 1; i <= playerNum; i++)
  {
    string playerName = "";

    cout << "Enter Player " << i << " name: ";
    cin >> playerName;

    names.push_back(playerName);
  }
}

void Game::set_win_condition()
{
  for (int i = 0; i < players_num; i++) {
    win_condition.push_back(false);
  }
}

// TODO: Set players array with Player objects.
// Shuffles the deck and deals to each Player.
// Sorts the Player vector according to their cards, in order to determine
// the correct ranking.
void Game::pregame()
{
  deck.shuffle();

  // Deal cards
  for (unsigned int i = 0; i < turns.size(); ++i) {
    assert(!deck.empty());
    turns[i].set_card(deck.deal_one());
    turns[i].set_turn(i);
  }

  // Sort order vector to determine the correct order.
  order = turns;

  sort(order.begin(), order.end(), PlayerComparator());

  for (unsigned int i = 0; i < players_num; i++) {
    order[i].set_order(i+1);
  }

  return;
}

void Game::set_cardNum(unsigned int cardNum_in)
{
  cardNum = cardNum_in;
}


void Game::round_one()
{
  string message = " estimate a position ( ";
  unsigned int guess_in = 0;

  for (int i = 0; i < players_num; i++) {
    message = message + to_string(i+1) + " ";
  }

  message += "): ";

  for (int i = 0; i < players_num; i++) {
    show_players(i);

    cout << turns[i].get_name() << message;
    cin >> guess_in;
    cout << "\n";

    cout << turns[i].get_name() << " predicts " << guess_in << " highest/lowest\n";
  }

}

void Game::round_two()
{
  string message = " lock in an answer ";

  for (int i = 0; i < players_num; i++) {
    message = message + to_string(i+1) + " ";
  }

  message += "): ";
  unsigned int guess_in = 0;

  for (int i = 0; i < players_num; i++) {
    show_players(i);

    cout << turns[i].get_name() << message;
    cin >> guess_in;
    cout << "\n";

    turns[i].set_guess(guess_in);

    if (turns[i].check_guess()) {
      cout << turns[i].get_name() << " is correct!\n";
      win_condition[i] = true;
    }
  }

}

void Game::end_game()
{
  unsigned int correct_num = 0;

  for (int i = 0; i < players_num; i++) {
    if (win_condition[i]) {
      correct_num++;
    }
  }

  cout << "The group got " << correct_num << " out of " << players_num << " correct\n";
  if (correct_num == players_num) {
    cout << "Congratulations! You beat Indian Poker!\n";
  }
  else {
    cout << "Better luck next time!\n";
  }

  return;
}

void Game::show_players(unsigned int current)
{
  for (int i = 0; i < players_num; i++) {
    if (i != current) {
      cout << turns[i].get_card().facade << " ";
    }
  }
}

void Game::play_game()
{
  round_one();

  round_two();

  end_game();
}

bool Game::get_play_condition()
{
  return play_condition;
}

void Game::flip_play_condition()
{
  play_condition = false;
}
