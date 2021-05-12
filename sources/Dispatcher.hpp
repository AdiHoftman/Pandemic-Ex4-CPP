#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class Dispatcher : public Player{

        public:
            Dispatcher(Board& b, City c) : Player(b, c, "Dispatcher"){}

            Player& fly_direct(City _city);

    };

};