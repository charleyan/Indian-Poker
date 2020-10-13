/*
  deck.cpp
  Implementation of deck.h
*/

#include "deck.h"

#include <vector>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

using std::vector;

// Default Constructor

Deck::Deck()
{

}


// Initiializes deck and the cards that are in the deck.
Deck::Deck(unsigned int size_in)
{
  for (unsigned int i = 2; i < (size_in+2); i++) {
    cards.push_back(Card(i));
  }

  size = size_in;
  next = 0;
}

// Returns top card and increments next index.
Card Deck::deal_one()
{
  assert(next < size);
  return cards[next++];
}

// Shuffles the deck and resets the next index.
// Shoutout to EECS 280 umich. See this link,
// https://en.wikipedia.org/wiki/In_shuffle
void Deck::shuffle()
{
  Card top = cards[size-1];
  bool isOdd = false;

  if (size % 2 == 1) {
    isOdd = true;
    cards.pop_back();
    size--;
  }

  vector<Card> temp(cards.begin(), cards.end());

  // Perform shuffle 3 times
  for (unsigned int i = 0; i < 3; ++i) {
    for (unsigned int j = 0; j < (size/2); ++i) {
      temp[j+(j+1)] = cards[j];
      temp[size-1-(j+j+1)] = cards[size-1-j];
    }
    cards = temp;
  }

  srand(time(NULL));

  cards.push_back(top);
  next = 0;

  return;
}

bool Deck::empty()
{
  return cards.empty();
}

void Deck::set_size(unsigned int size_in)
{
  size = size_in;
}
