/*********************************************************************
** Program Filename: gofish.cpp
** Author: Alejandro Morales
** Date: 8 May, 2022
** Description: You can play the game of GoFish!
** Input: Command line arguments, rank of card, play again
** Output: scoreboard: each player's hands,book, and turn.
*********************************************************************/

#include "game.h"

bool isPos(string num);
bool playagain();


//Barely goes over the 15 lines due to the argument lines
int main(int argc, char const *argv[]) {
    bool cheatMode = false;
    if(argc != 2) {
        cout << "Incorrect number of arguments: Must be either be true or false. Bye!" << endl;
        return 1;
    }

    if(strcmp(argv[1],"true") == 0) {
        cheatMode = true;
    } else if (strcmp(argv[1],"false") == 0)  {
        cheatMode = false;
    } else {
        cout << "Incorrect argument. Bye!" << endl;
        return 1;
    }

    do{
        Game gofish;
        gofish.set_cheatMode(cheatMode);
        gofish.setUp();
    } while(playagain() != 0);
    return 0;
}


/*****************************************************************
** Function: playagain
** Description: Determines if they want to play again.
** Parameters: No parameter
** Pre-Conditions: None, must be just called
** Post-Conditions: Returns 0 or 1 depending on what the user picks. 
*****************************************************************/
bool playagain() {
  cout << endl;
  string again;
  cout << "Do you want to play again (0-no or 1-yes)? ";
  cin >> again;
  bool check = false;
  while(check == false) {
      //checks to make sure it's either 0 or 1
      if(isPos(again) == true && (atoi(again.c_str()) == 0 || atoi(again.c_str()) == 1))     {
      cout << endl;
      return atoi(again.c_str());
    } else {
        cout << "Invalid input! Enter again: ";
        cin >> again;
    }
  }
}


/***************************************************************
** Function: isPos
** Description: Determines if it's a postive integer
** Parameters: A string
** Pre-Conditions: Must be a non empty string
** Post-Conditions: Prints out true or false depending if the string are all integers or not.
*****************************************************************/
bool isPos(string num) {
  for (int i = 0; i < num.length(); i++) {
    if (!((int(num[i]) > 47 && int(num[i]) < 58))) {
      return false;
    }
  }
  return true;
}