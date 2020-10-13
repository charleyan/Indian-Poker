#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <vector>
#include <stdlib.h>
#include <time.h>

using std::vector;

class Deck {
public:
    Deck();

    // Initiializes deck and the cards that are in the deck.
    Deck(unsigned int size_in);

    // Returns top card and increments next index.
    Card deal_one();

    // Shuffles the deck and resets the next index.
    // Shoutout to EECS 280 umich. See this link,
    // https://en.wikipedia.org/wiki/In_shuffle
    void shuffle();

    // Returns whether or not the deck is empty
    bool empty();

    void set_size(unsigned int size_in);

private:
  unsigned int size;
  vector<Card> cards;
  unsigned int next;
};

#endif
