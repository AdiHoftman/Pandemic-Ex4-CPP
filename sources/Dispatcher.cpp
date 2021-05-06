#include "Dispatcher.hpp"

using namespace std;

namespace pandemic{

    Player& Dispatcher::fly_direct(City _city){
        if(board.get_research_station().count(city) != 0){
            city = _city;
            return *this;
        }
        return Player::fly_direct(_city);
    }

};