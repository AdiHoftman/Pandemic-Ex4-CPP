#include "Researcher.hpp"

using namespace std;

const int cards_of_cure = 5;

namespace pandemic{

    Player& Researcher::discover_cure(Color color){
        int count = 0;
        for(const auto& key : card){
            if(colors_of_cities.at(key) == color){
                count++;
            }
        }
        if(count < cards_of_cure){
            throw std::invalid_argument{"illegal action: you only have "+std::to_string(count)+" "+ colors.at(color) + " cards remaining " };
        }
        count = 0;
        for(auto it = card.begin(); it != card.end(); count++){
            if(count == 4) { break; }
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