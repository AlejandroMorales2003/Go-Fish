#include "player.h"

Player::Player(){
	this->hand = Hand();						//intializes the hand
    this->books = new int[13];					//intializes the possible books to 13
    this->n_books = 0;							//intializes the number of books to 0
}

/******************************************************************
 * Function: Player() //copy constructor
 * Description: Copies the contents of the passed in players to the another object
 * Parameters: None
 * Pre-Conditions: must be a hand declared
 * Post-Conditions: copy of the contents
******************************************************************/
Player::Player(const Player & p){
    cout <<  "copy constructor" << endl;
    this->n_books = p.n_books;

    this->books = new int[this->n_books];
    for(int i = 0; i  < this->n_books; i++) {
        this->books[i] = p.books[i];
    }
}

/******************************************************************
 * Function: Player() //Assignment Overload Operator
 * Description: Copies the contents of the right operand to the left operand
 * Parameters: None
 * Pre-Conditions: must be a hand declared
 * Post-Conditions: copy of the old contents
******************************************************************/
Player& Player::operator=(const Player& p) {
    cout << "Assignment Operator Overload" << endl;

	if (this != &p){
		this->n_books = p.n_books;

		if (this->books != NULL) {
			delete [] this->books;
        }
		//deep copy
		this->books = new int[this->n_books];
		for (int i = 0; i < this->n_books; ++i)
			this->books[i] = p.books[i];	

	}
	return *this;
}

/******************************************************************
 * Function: ~Player()
 * Description: Destructor that deletes the dynamically created array of books
 * Parameters: None
 * Pre-Conditions: must be a int array of books declared
 * Post-Conditions: books is deleted
******************************************************************/
Player::~Player(){
	delete [] this->books;
	this->books = NULL;
}

/***************************************************************
** Function: getHand()
** Description: gets the hand from the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the hands of cards as a hand
*****************************************************************/
Hand& Player::getHand(){
	return this->hand;
}

/***************************************************************
** Function: getBooks()
** Description: gets the books from the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the int array of books as integer
*****************************************************************/
int* Player::getBooks() const{
	return this->books;
}

/***************************************************************
** Function: get_n_books()
** Description: gets the number of books in the int array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the numbers of books in the int array as an integer
*****************************************************************/
int Player::get_n_books() const{
	return this->n_books;
}

/***************************************************************
** Function: removeBook()
** Description: removes a book from the hand of the player
** Parameters: an integer
** Pre-Conditions: makes sure it's a valid rank
** Post-Conditions: removes cards from the hand of the player
*****************************************************************/
void Player::removeBook(int rank) {
    this->books[this->n_books] = rank;
	this->n_books++;

	while(hand.checkRankInHand(rank)) {
		hand.removeCard(rank);
	}
    
}