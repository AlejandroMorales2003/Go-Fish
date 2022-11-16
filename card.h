#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Card {
    private:
        int rank;  // Should be in the range 0-12.
        int suit;  // Should be in the range 0-3.
    public:
        Card();
        int get_suit() const;
        int get_rank() const;
        void set_suit(int s);
        void set_rank(int r);
        string map_suit() const;
        string map_rank() const;
        void print_card() const;
};

#endif

