#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class Scientist : public Player{

        int number;
        
        public:
            Scientist(Board& b, City c, int num) : Player(b, c, "Scientist"), number(num){}

            Player& discover_cure(Color color);
    };
};
