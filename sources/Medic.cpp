#include "Medic.hpp"

using namespace std;

namespace pandemic{

    // resets all the cure cubes when he treat at the specific city.
    Player& Medic::treat(City _city){
        if (city != _city) {
        throw std::invalid_argument("The city " + name_of_city.at(city) + " not " + name_of_city.at(_city));
        }
        if (board.disease_level[_city] == 0) {
            throw std::invalid_argument("There is no a cubes at " + name_of_city.at(_city));
        }
        board.disease_level[_city] = 0;
        return *this;
    }
    
    // when he drive to any city he resets the cubes cure at this city.
    Player& Medic::drive(City _city){
        Player::drive(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    // when he fly direct to any city he resets the cubes cure at this city.
    Player& Medic::fly_direct(City _city){
        Player::fly_direct(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    // when he fle charter to any city he resets the cubes cure at this city.
    Player& Medic::fly_charter(City _city){
        Player::fly_charter(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    // when he fly shuttle to any city he resets the cubes cure at this city.
    Player& Medic::fly_shuttle(City _city){
        Player::fly_shuttle(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }
};
