#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <string>

namespace pandemic{

    class Medic : public Player{


        public:
            map<Color, bool> health;
            Medic(Board& b, City c) : Player(b, c, "Medic"){}

            Player& treat(City _city);
            Player& drive(City _city);
            Player& fly_direct(City _city);
            Player& fly_charter(City _city);
            Player& fly_shuttle(City _city);
    };
};
