#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"

using namespace std;


    
    class Game{

        private:
        Player player1;
        Player player2;
        bool tieSit;
        
        public:
        string gameWinner;
        string turnWinner;

        Game(){}
        Game(Player const &player1, Player const &player2){
            this->player1 = player1;
            this->player2 = player2;
        };
        void playTurn(){};
        void printLastTurn(){};
        void playAll(){};
        void printWiner(){};
        void printLog(){};
        void printStats(){};

    //friend ostream &operator<<(ostream &os, const Game &game);

    ~Game(){};


    };


