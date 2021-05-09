#include "Dispatcher.hpp"

using namespace std;

namespace pandemic{

    Player& Dispatcher::fly_direct(City _city){
        if(city == _city){
            throw invalid_argument("illegal action: you can't fly to the city that you here at now");
        }
        if(board.get_research_station().count(city) != 0){
            //throw invalid_argument("there no have a research station");
            city = _city;
            return *this;
        }
            return Player::fly_direct(_city);
    }

};