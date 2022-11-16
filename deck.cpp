#include "deck.h"

//default constructors:sets the 52 cards in order
Deck::Deck() {
    int count = 0;
    for(int j = 0; j < 13; j++) {
        for(int k = 0; k < 4; k++) {
            this->cards[count].set_rank(j);             //sets the rank for the cards
            this->cards[count].set_suit(k);             //sets the suit for the cards
            count++;
        }
    }

    this->n_cards = 52;                                 //52 cards in the deck
}


/***************************************************************
** Function: get_cards()
** Description: gets the cards from the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the deck of cards as a card
*****************************************************************/
Card Deck::get_cards() const{ return this->cards[52]; }

/***************************************************************
** Function: get_n_cards()
** Description: gets the number of cards in the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the numbers of cards as an integer
*****************************************************************/
int Deck::get_n_cards() const{ return this->n_cards; }

/***************************************************************
** Function: print_deck()
** Description: prints the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the deck of cards
*****************************************************************/
void Deck::print_deck() const{
    for (int i = 0; i < this->n_cards; i++) {          //interates through the array of cards
        cards[i].print_card();                         //prints the array of cards
    }           
}

/***************************************************************
** Function: remove_card()
** Description: removes a card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: removes a card from the end of the deck of cards and decrements the number of cards
*****************************************************************/
Card Deck::remove_card() {
    Card c = cards[--this->n_cards];                    //removes cards from the end of array
    return c;
}

/***************************************************************
** Function: randomize()
** Description: randomizes the deck of cards
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: randomizes the deck of cards into different indexes
*****************************************************************/
void Deck::randomize() {
        srand(time(NULL));
    for (int i = this->n_cards - 1; i > 0; i--) {       //itertaes through the rray
        int j = rand() % (i + 1);                       //randomizes the index positions
        swap(&this->cards[i], &this->cards[j]);         //swaps the positions
    }
}


/***************************************************************
** Function: swap()
** Description: swaps cards in deck
** Parameters: two pointer cards
** Pre-Conditions: cards should be established
** Post-Conditions: swapped cards based on their indexes
*****************************************************************/
void Deck::swap (Card *a, Card *b) const{
    Card temp = *a;
    *a = *b;                                            //swaps the values in the indexes
    *b = temp;
}

//the randomize function was from geek to geeks https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/. I created the swap function.