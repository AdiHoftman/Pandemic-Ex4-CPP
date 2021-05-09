#include "Scientist.hpp"

using namespace std;

namespace pandemic{

    Player& Scientist::discover_cure(Color color) {
    if(board.get_research_station().count(city) == 0){
        throw std::invalid_argument{"illegal action: city "+ name_of_city.at(city)+" has no research station!"};
    }
    int count = 0;
    for(const auto& key : card){
        if(colors_of_cities.at(key) == color){
            count++;
        }
    }
    if(count < number){
        throw std::invalid_argument{"illegal action: you only have "+std::to_string(count)+" "+ colors.at(color) + " cards remaining " };
    }
    count = 1;
    for(auto it = card.begin(); it != card.end(); count++){
        if(count == number) { break; }
        if(colors_of_cities.at(*it) == color) {
            it = card.erase(it);
        }
        else {
            ++it;
        }
    }
    board.set_discovered_cure(color);
    return *this;
}
};