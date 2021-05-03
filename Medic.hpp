#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <string>

namespace pandemic{

    class Medic : public Player{


        public:
            Medic(Board& b, City c) : Player(b, c, "Medic"){}

            Player& treat(City _city);
    };
};
