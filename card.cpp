#include "card.h"

//default constructor
Card::Card() {
    this->rank = 3;
    this->suit = 1;
}

/***************************************************************
** Function: get_rank()
** Description: gets the rank
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the rank as an integer
*****************************************************************/
int Card::get_rank() const{ return this->rank;}

/***************************************************************
** Function: get_suit()
** Description: gets the suit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the suit as an integer
*****************************************************************/
int Card::get_suit() const{ return this->suit;}

/***************************************************************
** Function: set_rank()
** Description: sets the rank to a card
** Parameters: an integer
** Pre-Conditions: an integer between 0-12
** Post-Conditions: sets the card rank to the rank chosen
*****************************************************************/
void Card::set_rank(int r) { this->rank = r;}

/***************************************************************
** Function: set_rank()
** Description: sets the rank to a card
** Parameters: an integer
** Pre-Conditions: an integer between 0-12
** Post-Conditions: sets the card rank to the rank chosen
*****************************************************************/
void Card::set_suit(int s) { this->suit = s;}

/***************************************************************
** Function: map_rank()
** Description: sets the rank to designated card value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a string with card value
*****************************************************************/
string Card::map_rank() const{   //ace, jack, queen, king
    if(this->rank == 0) {
        return "A";
    } else if(this->rank == 10) {
        return "J";
    } else if(this->rank == 11) {
        return "Q";
    } else if(this->rank == 12) {
        return "K";
    }else {
       return to_string(this->rank + 1);
    }
}

/***************************************************************
** Function: map_suit()
** Description: sets the suit to designated card value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a string with suit value
*****************************************************************/
string Card::map_suit() const{   //diamonds, clubs, hearts, and spades
       if(this->suit == 0) {
        return "Clubs";
    } else if(this->suit == 1) {
        return "Diamonds";
    } else if(this->suit == 2) {
        return "Hearts";
    } else if(this->suit == 3) {
        return "Spades";
    }
}

/***************************************************************
** Function: print_card()
** Description: prints the card
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the card
*****************************************************************/
void Card::print_card() const{
    cout << "Rank: ";
    cout << map_rank();
    cout << " Suit: ";
    cout << map_suit(); 
    cout << "   ";

}

