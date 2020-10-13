// Main file that runs Indian Poker
// Written by Charles Yan 2020

#include "game.h"

#include <iostream>

using std::cout;
using std::cin;

int main() {
  cout << "-----------------------\n";
  cout << "Welcome to Indian Poker\n";
  cout << "-----------------------\n\n";

  Game game;

  game.pregame();

  while(game.get_play_condition()) {
    char input;

    game.pregame();

    game.play_game();

    cout << "Play again? (y or n): ";
    cin >> input;
    cout << "\n";

    if (input == 'n') {
      game.flip_play_condition();
    }
  }

  cout << "------------------\n";
  cout << "Thanks for playing\n";
  cout << "------------------\n";

  return 0;
}
