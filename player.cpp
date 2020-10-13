/* player.cpp
  Implmentation of player.h
*/

#include "player.h"

Player::Player(string name_in, unsigned int turn_in)
{
  name = name_in;
  turn = turn_in;
}

void Player::set_card(Card card_in)
{
  card = card_in;
}

void Player::set_turn(unsigned int turn_in)
{
  turn = turn_in;
}

void Player::set_order(unsigned int order_in)
{
  order = order_in;
}

Card & Player::get_card()
{
  return card;
}

void Player::set_guess(unsigned int guess_in)
{
  guess = guess_in;
}

string Player::get_name()
{
  return name;
}

bool Player::check_guess()
{
  return guess == order;
}
