#include "GeneSplicer.hpp"

using namespace std;

const int cards_of_cure = 5;

namespace pandemic{

    Player& GeneSplicer::discover_cure(Color color){
        if(board.get_research_station().count(city) == 0){
        throw std::invalid_argument{"illegal action: city "+name_of_city.at(city)+" has no research station!"};
        }
        if(cards_of_cure > card.size()){
            throw std::invalid_argument{"illegal action: you only have "+std::to_string(card.size())+" "+ colors.at(color) + " cards remaining " };
        }
        int count = 0;
        for(auto it = card.begin(); it != card.end(); count++){
            if(count == 4) { break; }
            it = card.erase(it);
        }
        board.set_discovered_cure(color);
        return *this;
    }
};