
#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
using namespace std;

namespace ariel{}
using namespace ariel;

    class Player
    {
    public:
    string playerName;
    int currNumCards;
    int cardsWin;

    Player(){}
    Player(const string name){};

    int stacksize(){
        return this->currNumCards;
    };
    int cardesTaken(){
        return this->cardsWin;
    };

    ~Player(){}

    };

