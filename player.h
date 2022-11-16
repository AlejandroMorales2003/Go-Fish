#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"

class Player {
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books. 
        int n_books;
    public:
        Player();

        ~Player();

        Player(const Player &);

        Player& operator=(const Player &);

        Hand& getHand();

        int* getBooks() const;

        int get_n_books() const;

        void removeBook(int rank);
};

#endif