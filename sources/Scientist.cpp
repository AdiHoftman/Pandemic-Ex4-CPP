#include "Scientist.hpp"

using namespace std;

namespace pandemic{

    // can discover cure that he have less than 5 cards.
    Player& Scientist::discover_cure(Color color) {
    if(board.get_research_station().count(city) == 0){
        throw std::invalid_argument("There is no a research station at "+ name_of_city.at(city));
    }
    int counter = 0;
    for(const auto& key : card){
        if(colors_of_cities.at(key) == color){
            counter++;
        }
    }
    if(counter < number){
        throw std::invalid_argument("You have only " + std::to_string(counter) + " of color " + colors.at(color) + " cards");
    }
    counter = 1;
    for(auto c = card.begin(); c != card.end(); counter++){
        if(colors_of_cities.at(*c) == color) {
            c = card.erase(c);
        }
        else {
            ++c;
        }
    }
    board.set_discovered_cure(color);
    return *this;
}
};