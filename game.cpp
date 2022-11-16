#include "game.h"

Game::Game() {
    this->cards;                    
    this->players;
    this->cheatMode = false;                //sets the cheatmode to false
}

/***************************************************************
** Function: set_cheatMode()
** Description: sets the cheatmode to something else
** Parameters: a boolean
** Pre-Conditions: a boolean from main
** Post-Conditions: sets the cheatmode to either true or false
*****************************************************************/
void Game::set_cheatMode(bool cheatMode) {
    this->cheatMode = cheatMode;
}

/***************************************************************
** Function: isPos
** Description: Determines if it's a postive integer
** Parameters: A string
** Pre-Conditions: Must be a non empty string
** Post-Conditions: Prints out true or false depending if the string are all integers or not.
*****************************************************************/
bool Game::isPos(string num) {
  for (int i = 0; i < num.length(); i++) {
    if (!((int(num[i]) > 47 && int(num[i]) < 58))) {
      return false;
    }
  }
  return true;
}

/***************************************************************
** Function: getRank()
** Description: gets the rank for the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints out a valid rank from the players hand
*****************************************************************/
int Game::getRank(){
  string num;
  cout << "It the your turn!" << endl;
  cout << "Enter the rank you would like to get from the opponent (1 = \"Ace\" through 13 = \"King\"): ";
  cin >> num;
  bool check = false;
  while (check == false) {

    if (isPos(num) == true && atoi(num.c_str()) > 0 && atoi(num.c_str()) < 14) {
        //checks to make sure the rank is in the hand
        if(players[0].getHand().checkRankInHand(atoi(num.c_str())) == true) {
            cout << endl;
            return atoi(num.c_str());
        } else {
            //error check if the card is not in hand
            cout << "Not in your hand. Try again: ";
            cin >> num;
        }
    } else {
        //error check if it's not in range or an integer
        cout << "Invalid Input. Please try again!" << endl;
        cin >> num;
    }
  }
}

/***************************************************************
** Function: getRankComputer()
** Description: gets the rank for the computer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints out a valid rank from the computers hand
*****************************************************************/
int Game::getRankComputer() {
    cout << "It's the computer's turn!" << endl;
    int index = rand() % players[1].getHand().get_n_cards();
    int randRank = players[1].getHand().getCards()[index].get_rank();
    return randRank + 1;
}

/***************************************************************
** Function: setUp()
** Description: sets up the game and starts the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the game begins and ends here
*****************************************************************/
void Game::setUp() {
    cards.randomize();                                  //randomizes the cards in the array

    players[0].getHand().setHand(cards);                //sets the players hand
    players[1].getHand().setHand(cards);                //sets the computers hand

    bool finished = false;                              //to determine if the game is over

    while(finished == false) {                          //runs the entire game by alternating turns
        playerTurn(finished);                        
        checkAndRemoveBooks(0);
        computerTurn(finished);
        checkAndRemoveBooks(1);
    }  
    scoreBoard();                                       //prints the ending books
    gameWinner();                                       //determines the winner


}

/***************************************************************
** Function: gameIsOver()
** Description: determines if the game is over
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if the game is over
*****************************************************************/
bool Game::gameIsOver() {
    if(players[0].get_n_books() + players[1].get_n_books() == 13) {
        return true;
    }
    return false;
}

/***************************************************************
** Function: scoreboard()
** Description: prints the status of the game based on cheat mode
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the status of the game based on the player and computer
*****************************************************************/
void Game::scoreBoard() {
    playerDisplay();
    if(this->cheatMode == true) {
        computerDisplay();
    }
}

/***************************************************************
** Function: intToRank()
** Description: turns the books from a integer to string
** Parameters: an integer
** Pre-Conditions: make sure it's a valid rank
** Post-Conditions: outputs the the string based on the rank
*****************************************************************/
string Game::intToRank(int rank) {
    string change[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    return change[rank - 1];
}

/***************************************************************
** Function: playerDisplay()
** Description: prints the status of the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the status of the player
*****************************************************************/
void Game::playerDisplay() {
    cout << "-------Here are your cards";
    cout << "----------------------------------------------------------------------------------" << endl;
    players[0].getHand().printHand();
    cout << endl;
    cout << "Amount of Books laid down by you: ";
    for(int i = 0; i < players[0].get_n_books(); i++) {
        cout << intToRank(players[0].getBooks()[i]) << " ";
    }
    cout << "            " << endl;

    cout << "Amount of Books laid down by the computer: ";
     for(int i = 0; i < players[1].get_n_books(); i++) {
        cout << intToRank(players[1].getBooks()[i]) << " ";
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

/***************************************************************
** Function: computerDisplay()
** Description: prints the status of the computer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs the status of the computer
*****************************************************************/
void Game::computerDisplay(){
    cout << "-------Here are the computers cards";
    cout << "------------------------------------------------------------------------" << endl;
    players[1].getHand().printHand();
    cout << endl;
    cout << "Amount of Books laid down by the computer: ";
     for(int i = 0; i < players[1].get_n_books(); i++) {
        cout << intToRank(players[1].getBooks()[i]) << " ";
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << endl;
}

/***************************************************************
** Function: playerTurn()
** Description: established all the functions for the turn of the player
** Parameters: a boolean
** Pre-Conditions: a valid boolean
** Post-Conditions: determines if the games is over, drawing, checking and removing cards,
*****************************************************************/
void Game::playerTurn(bool &gameOver) {
    gameOver = gameIsOver();
    if (gameOver == true) {
        return;
    }
    scoreBoard();
    if(players[0].getHand().get_n_cards() == 0 && gameOver == false) {
        draw(0);
        return;
    }
    gameOver = gameIsOver();
    int rank = getRank();
    cout << "You chose " << rank << "!" << endl;
    matchingComp(rank,gameOver);
    gameOver = gameIsOver();
}

/***************************************************************
** Function: computerTurn()
** Description: established all the functions for the turn of the computer
** Parameters: a boolean
** Pre-Conditions: a valid boolean
** Post-Conditions: determines if the games is over, drawing, checking and removing cards,
*****************************************************************/
void Game::computerTurn(bool &gameOver) {
    gameOver = gameIsOver();
    if (gameOver == true) {
        return;
    }
    scoreBoard();
    if(players[1].getHand().get_n_cards() == 0 && gameOver == false) {
        draw(1);
        return;
    }
    gameOver = gameIsOver();
    int rank = getRankComputer();
    cout << "The computer chose " << rank << "!" << endl;
    matchingPlayer(rank,gameOver);
    gameOver = gameIsOver();
}

/***************************************************************
** Function: matchingComp()
** Description: steals cards from the other player, and  calls the go fish functionality
** Parameters: an integer and boolean
** Pre-Conditions: a valid boolean
** Post-Conditions: cards are transported and added to players hand
*****************************************************************/
void Game::matchingComp(int rank, bool &gameOver) {
    int count = 0;
    bool again = true;
    while(again == true) {
        gameOver = gameIsOver();
        if(gameOver == true) {
            return;
        }
        count = 0;
        steelCardsforPlayer(rank,again,count,gameOver);
    }
    //0 is inputed into the function because it's the first player
    if(count == 0) {                                            //human draws a card
        goFish(0);     
        players[0].getHand().sort();
        checkAndRemoveBooks(0);
    }
    checkAndRemoveBooks(0);
}

/***************************************************************
** Function: stealCardsforPlayer()
** Description: matchingComp go too long so I made separated it
** Parameters two bools, and two integers
** Pre-Conditions: valid rank, and booleans
** Post-Conditions: steals cards from the other player
*****************************************************************/
void Game::steelCardsforPlayer(int rank, bool &again, int &count, bool &gameOver) {
    while(players[1].getHand().checkRankInHand(rank)) {
        Card take = players[1].getHand().removeCard(rank);      //removes card from computer
        cout << "You got a card" << endl;
        players[0].getHand().addCard(take);                     //adds card to the human
        count++;
        checkAndRemoveBooks(0);
    }
    if(count == 0) {
        again = false;
    } else {
        if(players[0].getHand().get_n_cards() != 0) {
            if(players[1].getHand().get_n_cards() == 0 && gameOver == false) {
                draw(0);
                return;
            }
            scoreBoard();
            rank = getRank();
            cout << "You chose " << rank << "!" << endl;
        }
    } 
}

/***************************************************************
** Function: matchingPlayer()
** Description: steals cards from the other player, and  calls the go fish functionality
** Parameters: an integer and boolean
** Pre-Conditions: a valid boolean
** Post-Conditions: cards are transported and added to players hand
*****************************************************************/
void Game::matchingPlayer(int rank,bool &gameOver) {
    int count = 0;
    bool again = true;
    while(again == true) {
        gameOver = gameIsOver();
        if(gameOver == true) {
            return;
        }
        count = 0;
        steelCardsforComputer(rank,again,count,gameOver);
    }
    //0 is inputed into the function because it's the first player
    if(count == 0) {                                            //human draws a card
        goFish(1);
        players[1].getHand().sort();
        checkAndRemoveBooks(1);
    }
    checkAndRemoveBooks(1);
}

/***************************************************************
** Function: stealCardsforPlayer()
** Description: matchingPlayer go too long so I made separated it
** Parameters two bools, and two integers
** Pre-Conditions: valid rank, and booleans
** Post-Conditions: steals cards from the other player
*****************************************************************/
void Game::steelCardsforComputer(int rank, bool &again, int &count, bool &gameOver) {
    while(players[0].getHand().checkRankInHand(rank)) {
        Card take = players[0].getHand().removeCard(rank);      //removes card from computer
        cout << "The computer got a card" << endl;
        players[1].getHand().addCard(take);                     //adds card to the human
        count++;
    }
    if(count == 0) {
        again = false;
    } else {
        if(players[1].getHand().get_n_cards() != 0) {
            if(players[0].getHand().get_n_cards() == 0 && gameOver == false) {
                draw(0);
                return;
            }
            scoreBoard();
            rank = getRankComputer();
            cout << "The computer chose " << rank << "!" << endl;
        }
    }
}

/***************************************************************
** Function: goFish()
** Description: whatever player gets a card from the deck
** Parameters: integer
** Pre-Conditions: a valid player number
** Post-Conditions: a player gets a card from the deck into their hand
*****************************************************************/
void Game::goFish(int player) {
    cout << "Go fish!" << endl;
    players[player].getHand().addCardNoSort(cards.remove_card());
    if(this->cheatMode == true) {
        if(player == 0) {
        cout << "You got a ";
        } else {
        cout << "The computer got a ";
        }
        int index = players[player].getHand().get_n_cards() - 1;
        players[player].getHand().getCards()[index].print_card();
        cout << endl;
    }
}

/***************************************************************
** Function: draw()
** Description: draws a card from the deck when they have no cards left
** Parameters: integer
** Pre-Conditions: a valid player number
** Post-Conditions: a player gets a card from the deck into their hand
*****************************************************************/
void Game::draw(int player) {
    if(player == 0) {
        cout << "You draw a card" << endl;
    } else {
        cout << "The computer draws a card" << endl;
    }
    players[player].getHand().addCard(cards.remove_card());
}

/***************************************************************
** Function:checkAndRemoveBooks()
** Description: checks for books in hand and then removes them
** Parameters: integer
** Pre-Conditions: a valid player number
** Post-Conditions: books are removed from the players hand and prompted
*****************************************************************/
void Game::checkAndRemoveBooks(int player) {
    string promptPlayer;
    if(player == 0) {
        promptPlayer = "You ";
    } else {
        promptPlayer = "The computer ";
    }
    for(int i = 1; i < 14; i++) {                               //check for books
        if(players[player].getHand().checkBook(i) == true) {
            players[player].removeBook(i);
            cout << promptPlayer << "got a book!" << endl;
        }
    }
}

/***************************************************************
** Function: gameWinner()
** Description: determines the game winner
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: outputs to the console the winner
*****************************************************************/
void Game::gameWinner() const{
    if(players[0].get_n_books() > players[1].get_n_books()) {
        cout << "You win!";
    } else {
        cout << "The computer wins!";
    }
}