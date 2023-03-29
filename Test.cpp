
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

TEST_CASE("case of invalid number of cards/ names"){

Player p1("Alice");
Player p2("Bob");

CHECK(p1.playerName != p2.playerName);

Game game(p1, p2);

CHECK(p1.currNumCards == 26);
CHECK(p2.currNumCards == 26);
CHECK(game.gameWinner == " ");

for (int i=0;i<6;i++) {
    CHECK_NOTHROW(game.playTurn());
}

CHECK(p1.currNumCards < 26);
CHECK(p2.currNumCards < 26);

if(game.gameWinner == p1.playerName){
    CHECK(p2.currNumCards > p1.currNumCards);
} else{
    CHECK(p1.currNumCards > p2.currNumCards);
}

}



TEST_CASE("cards winner in curr turn"){

Player p1("Alice");
Player p2("Bob");

CHECK(p1.playerName != p2.playerName);

Game game(p1, p2);

for (int i=0;i<10;i++) {
    int temp = p2.currNumCards;
    CHECK_NOTHROW(game.playTurn());
    if(game.turnWinner == p1.playerName){
        int c_temp = temp - p1.cardsWin;
        CHECK(p2.currNumCards == c_temp);
    }
    CHECK(game.turnWinner != " ");
}
CHECK(game.gameWinner == " ");
CHECK_NOTHROW(game.playAll());
CHECK(game.gameWinner != " ");
}


TEST_CASE("check after play all game"){

Player p1("ameer");
Player p2("Bob");

CHECK(p1.playerName != p2.playerName);

Game game(p1, p2);

CHECK_NOTHROW(game.playAll());
CHECK(p1.stacksize() == 0);
CHECK(p2.stacksize() == 0);
CHECK_NOTHROW(game.printWiner());
CHECK(game.gameWinner != " ");

}

