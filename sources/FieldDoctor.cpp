#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic{

    Player& FieldDoctor::treat(City _city){
        if(city != _city && connect_cities.at(city).count(_city) == 0){
            throw invalid_argument("You are not in city " + name_of_city.at(_city));
        }
        
        if(board[_city] == 0){
            throw invalid_argument("At " + name_of_city.at(_city) + "no have disease cubes");
        }
        if(board.is_cure(colors_of_cities.at(_city))){
            board[_city] = 0;
        }
        else{board[_city]--;}
        return *this;
    }
};