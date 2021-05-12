#include "Dispatcher.hpp"

using namespace std;

namespace pandemic{

    // if the dispatcher located in a city that has a research station he can fly direct without a card of the city.
    Player& Dispatcher::fly_direct(City _city){
        if(city == _city){
            throw invalid_argument("You can't fly to the city that you here at now");
        }
        if(board.get_research_station().count(city) != 0){
            city = _city;
            return *this;
        }
        return Player::fly_direct(_city);
    }

};