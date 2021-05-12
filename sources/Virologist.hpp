#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <string>

namespace pandemic{

    class Virologist : public Player{


        public:
            Virologist(Board& b, City c) : Player(b, c, "Virologist"){}

            Player& treat(City _city);
    };
};
