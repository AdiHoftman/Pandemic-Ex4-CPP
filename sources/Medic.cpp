#include "Medic.hpp"

using namespace std;

namespace pandemic{

    Player& Medic::treat(City _city){
        if (city != _city) {
        throw std::invalid_argument{"The current city is " + name_of_city.at(city) + " not " + name_of_city.at(_city) + ". Can not treat."};
        }
        if (board.disease_level[_city] == 0) {
            throw std::invalid_argument{"There is no pollution in the current city. Can not treat."};
        }
        board.disease_level[_city] = 0;
        return *this;
    }

    Player& Medic::drive(City _city){
        Player::drive(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City _city){
        Player::fly_direct(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City _city){
        Player::fly_charter(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City _city){
        Player::fly_shuttle(_city);
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[city] = 0;
        }
        return *this;
    }
};
