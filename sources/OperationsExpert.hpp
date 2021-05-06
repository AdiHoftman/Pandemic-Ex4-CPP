#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class OperationsExpert : public Player{

        public:
            OperationsExpert(Board& b, City c) : Player(b, c, "OperationsExpert"){}

            Player& build() override;
            
    };
};
