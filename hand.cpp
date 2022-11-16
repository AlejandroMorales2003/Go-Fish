#include "hand.h"

//default constructor
Hand::Hand(){
    this->cards = new Card[52];                 //intializes the hand to have up 52 cards
    this->n_cards = 0;                          //intializes the number of cards to 0
}

/******************************************************************
 * Function: ~Hand()
 * Description: Destructor that deletes the dynamically created array of cards
 * Parameters: None
 * Pre-Conditions: must be a hand declared
 * Post-Conditions: cards is deleted
******************************************************************/
Hand::~Hand() {
    if (this->cards != NULL){
		delete [] this->cards;                  //deletes the array of cards
		this->cards= NULL;
	}
}

/******************************************************************
 * Function: Hand() //copy constructor
 * Description: Copies the contents of the passed in hands to the another object
 * Parameters: None
 * Pre-Conditions: must be a hand declared
 * Post-Conditions: copy of the contents
******************************************************************/
Hand::Hand(const Hand& h) {
    this->n_cards = h.n_cards;                  //sets the number of cards into the new object

    this->cards = new Card[this->n_cards];      //creates a new array to copy the information into 

    for(int i = 0; i < this->n_cards; i++) {
        this->cards[i] = h.cards[i];
    }
 }

/******************************************************************
 * Function: Hand() //Assignment Overload Operator
 * Description: Copies the contents of the right operand to the left operand
 * Parameters: None
 * Pre-Conditions: must be a hand declared
 * Post-Conditions: copy of the old contents
******************************************************************/
Hand& Hand::operator =(const Hand& h) {
	if (this != &h){
		this->n_cards = h.n_cards;

        if (this->cards != NULL) {
			delete [] this->cards;
        }
		//deep copy
		for (int i = 0; i < this->n_cards; ++i) {
			this->cards[i] = h.cards[i];	
        }

	}
	return *this;
}

/***************************************************************
** Function: getCards()
** Description: gets the cards from the hand
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the hand of cards as a card
*****************************************************************/
Card* Hand::getCards() const{
    return this->cards;
}

/***************************************************************
** Function: get_n_cards()
** Description: gets the number of cards in the hand
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the numbers of cards as an integer
*****************************************************************/
int Hand::get_n_cards() const{
    return this->n_cards;
}

/***************************************************************
** Function: setHand()
** Description: gets the number of cards in the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the numbers of cards as an integer
*****************************************************************/
void Hand::setHand(Deck &d) { 
    int j = d.get_n_cards() - 1;
    this->n_cards = 7;                          //sets the hands to 7 cards
    this->cards = new Card[this->n_cards];      //allocates memory
    for(int i = 0; i < 7; i++) {             
        this->cards[i] = d.remove_card();       //removes 7 cards from the deck
        j--;
    }
    sort();                                     //sorts the hand from least to greatest
}

/***************************************************************
** Function: print_deck()
** Description: prints the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the deck of cards
*****************************************************************/
void Hand::printHand(){
    for(int i = 0; i < this->n_cards; i++) {
        this->cards[i].print_card();
        if((i != 0) && (i % 4 == 0)) {          //prints the hand in lines of 4 cards
            cout << endl;
        }
    }
}

/***************************************************************
** Function: add_card()
** Description: adds a card to the hand
** Parameters: a card
** Pre-Conditions: a card from the deck or from the other player
** Post-Conditions: adds a card to the end of the players hand(sorted)
*****************************************************************/
void Hand::addCard(Card c){

	//1. allocate a new Car array with num_cars+1
	Card* temp = new Card[this->n_cards + 1];

	//2. copy from the old car_arr into new car array using loop
	for (int i = 0; i < this->n_cards; ++i){
		temp[i] = this->cards[i];
	}
	temp[this->n_cards] = c;

	//3. free the memory of old car_arr, otherwise mem leaks
	delete [] this->cards;

	//4. assign new car array to car_arr;
	this->cards = temp;

	//5. increment num_cars by 1
	this->n_cards++;

    //sorts the hand from least to greatest
    sort();
}

/***************************************************************
** Function: add_cardNoSort()
** Description: adds a card to the hand
** Parameters: a card
** Pre-Conditions: a card from the deck or from the other player
** Post-Conditions: adds a card to the end of the players hand (without the sort)
*****************************************************************/
void Hand::addCardNoSort(Card c){

	//1. allocate a new Car array with num_cars+1
	Card* temp = new Card[this->n_cards + 1];

	//2. copy from the old car_arr into new car array using loop
	for (int i = 0; i < this->n_cards; ++i){
		temp[i] = this->cards[i];
	}
	temp[this->n_cards] = c;

	//3. free the memory of old car_arr, otherwise mem leaks
	delete [] this->cards;

	//4. assign new car array to car_arr;
	this->cards = temp;

	//5. increment num_cars by 1
	this->n_cards++;

}

/***************************************************************
** Function: checkRankInHand()
** Description: makes sure a particular rank is in the hand of the player
** Parameters: an integer
** Pre-Conditions: must be a valid rank number
** Post-Conditions: returns true if there is a matching rank
*****************************************************************/
bool Hand::checkRankInHand(int rank){
    for(int i = 0; i < this->n_cards; i++) {
        if(this->cards[i].get_rank() == rank -1) {          //checks to see if rank is in hand
            return true;
        }
    }
    return false;
}

/***************************************************************
** Function: checkBook()
** Description: makes sure theres isn't a book in hand
** Parameters: an integer
** Pre-Conditions: must be a valid rank number
** Post-Conditions: returns true if there is a book in hand
*****************************************************************/
bool Hand::checkBook(int rank) const{
    int count = 0;
    for(int i = 0; i <this->n_cards; i++) {
        if(this->cards[i].get_rank() == rank -1) {
            count++;
        }
    }

    if(count == 4) {                                        //if there are four cards, it's a book
        return true;
    }
    return false;
}

/***************************************************************
** Function: removeCard()
** Description: removes a card from the hand
** Parameters: an integer
** Pre-Conditions: a valid rank
** Post-Conditions: removes a card from the end of the hand and decrements the number of cards
*****************************************************************/
Card Hand::removeCard(int rank) {
    Card remove;
    int num = -10;
    for(int i = 0; i < this->n_cards; i++) {
        if(this->cards[i].get_rank() == rank - 1) {
            num = i;
        }
    }
    remove = this->cards[num];
    this->cards[num].set_rank(50);
    sort();
    this->n_cards--;
    return remove;
}

/***************************************************************
** Function: sort()
** Description: organizes the hands of the rank (least to greatest)
** Parameters: none
** Pre-Conditions: hands should be established
** Post-Conditions: returns an organized hand from least to greatest
*****************************************************************/
void Hand::sort() {
    Card temp;
    bool loop = false;
    while(loop == false) {                      //continues to organize until nothing moves
    int count = 0;                              //count indicates if there is swapping
    for(int i = 0; i < this->n_cards -1; i++) {
        if(this->cards[i].get_rank() > this->cards[i+1].get_rank()) {
            temp = this->cards[i];              //temperorary variable for th first

            this->cards[i] = this->cards[i+1];  //set the second index to the first
            this->cards[i+1] = temp;
            count++;
        }
    }
        if (count == 0) {                       //if there is no swapping, it's done
            loop = true;
        }
    }
}

