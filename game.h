#ifndef GAME_H
#define GAME_H
#include "player.h"
class Game {
    private:
        Deck cards;
        Player players[2];
        bool cheatMode;
    public:
        Game();
        void set_cheatMode(bool);
        void setUp();
        void playerTurn(bool &gameOver);
        void winner();
        bool gameIsOver();
        void scoreBoard();
        bool isPos(string num);
        int getRank(); 
        void matchingComp(int rank, bool &gameOver);
        void playerDisplay();
        void computerDisplay();
        string intToRank(int rank);
        void goFish(int player);
        void checkAndRemoveBooks(int player);
        void computerTurn(bool &gameOver);
        int getRankComputer(); 
        void matchingPlayer(int rank, bool &gameOver);
        void draw(int player);
        void gameWinner() const;
        void steelCardsforPlayer(int rank, bool &again, int &count, bool &gameover);
        void steelCardsforComputer(int rank, bool &again, int &count, bool &gameOver);
};

#endif