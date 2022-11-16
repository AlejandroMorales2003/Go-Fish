#ifndef HAND_H
#define HAND_H
#include "deck.h"

class Hand {
    private:
        Card* cards;  // An array of cards in hand
        int n_cards;  // Number of cards in the hand.
    public:

        Hand();
        ~Hand();

        Hand(const Hand&);
        Hand& operator=(const Hand&);

        //getters
        Card* getCards() const;
        int get_n_cards() const;

        void addCard(Card c);
        void addCardNoSort(Card c);
        Card removeCard(int rank);
        
        void setHand(Deck &d);
        void printHand();
        void sort();

        bool checkRankInHand(int rank);
        bool checkBook(int rank) const;
};


#endif