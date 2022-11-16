#ifndef DECK_H
#define DECK_H
#include "card.h"


class Deck {
    private:
        Card cards[52];     //A full deck of cards
        int n_cards;        // Number of cards remaining in the deck. 
    public:
        //constructors
        Deck();
        Deck(Card, int);

        //getters
        Card get_cards() const;
        int get_n_cards() const;

        //normal functions
        void print_deck() const;
        Card remove_card();
        void randomize();
        void swap(Card *a,Card *b) const;
};

#endif