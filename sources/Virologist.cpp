#include "Virologist.hpp"

using namespace std;

namespace pandemic{

    Player& Virologist::treat(City _city){
        if(card.count(_city) == 0 && city != _city){
            throw invalid_argument("You are not in city " + name_of_city.at(_city));
        }
        card.erase(_city);
        if(board.disease_level[_city] == 0){
            throw invalid_argument("At " + name_of_city.at(_city) + " no have disease cubes");
        }
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
            board.disease_level[_city] = 0;
        }
        else{board.disease_level[_city]--;}
        return *this;
    }
};