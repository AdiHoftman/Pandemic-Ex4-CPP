#include "Player.hpp"
#include "Board.hpp"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace pandemic{

    Player& Player::drive(City _city){
        return *this;
    }

    Player& Player::fly_direct(City _city){
        return *this;
    }

    Player& Player::fly_charter(City _city){
        return *this;
    }

    Player& Player::fly_shuttle(City _city){
        return *this;
    }

    Player& Player::build(){
        return *this;
    }
    
    Player& Player::discover_cure(Color color){
        return *this;
    }

    Player& Player::treat(City _city){
        return *this;
    }

    Player& Player::take_card(City _city){
        return *this;
    }
};