#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic{

    // can treat not just at the city that he located it, he can treat at city that neighbor to the city that he located it,
    // without to use card of the city.
    Player& FieldDoctor::treat(City _city){
        if(city != _city && connect_cities.at(city).count(_city) == 0){
            throw invalid_argument("You are not in city " + name_of_city.at(_city));
        }
        if(board.disease_level[_city] == 0){
                throw invalid_argument("At " + name_of_city.at(_city) + "no have disease cubes");
        }
        if(board.get_discovered_cure().count(colors_of_cities.at(city)) != 0){
               board.disease_level[_city] = 0;
               return *this;
        }
        board.disease_level[_city]--;
        return *this;
    }
};