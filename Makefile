CC=g++ -std=c++11 -g
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): game.o player.o hand.o deck.o card.o gofish.cpp
	$(CC) game.o player.o hand.o deck.o card.o gofish.cpp -o $(EXE_FILE)
deck.o: deck.cpp
	$(CC) -c deck.cpp
card.o:	card.cpp
	$(CC) -c card.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
game.o: game.cpp
	$(CC) -c game.cpp
clean:
	rm -f *.o $(EXE_FILE)
