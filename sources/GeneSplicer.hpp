#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{
    
    class GeneSplicer : public Player{

        public:
            GeneSplicer(Board& b, City c) : Player(b, c, "GeneSplicer"){}

            Player& discover_cure(Color color);
    };
};