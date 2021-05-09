#include "Player.hpp"
#include "Board.hpp"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

const int cards_of_cure = 5;

namespace pandemic{

    Player& Player::drive(City _city){
        if(connect_cities.at(_city).count(city) == 0 && connect_cities.at(city).count(_city) == 0){
            throw std::invalid_argument{"The city " + name_of_city.at(city) + " don't have a connect with " + name_of_city.at(_city)};
        }
        if(city == _city){throw invalid_argument("illegal action: you can't drive to the city that you here at now");}
        city = _city;
        return *this;
    }

    Player& Player::fly_direct(City _city){
        if(card.count(_city) == 0){
            throw invalid_argument("illegal action: you discarded the " + name_of_city.at(_city) + " card to discover a cure, so you cannot use this card.");
        }
        if(city == _city){throw invalid_argument("illegal action: you can't fly to the city that you here at now");}
        card.erase(_city);
        city = _city;
        return *this;
    }

    Player& Player::fly_charter(City _city){
        if(card.count(city) == 0){
            throw invalid_argument("illegal action: you do not have the " + name_of_city.at(city) + " card (the card of the city you are in).");
        }
        if(city == _city){throw invalid_argument("illegal action: you can't fly to the city that you here at now");}
        card.erase(city);
        city = _city;
        return *this;
    }

    Player& Player::fly_shuttle(City _city){
        if (board.get_research_station().count(city) == 0){
        throw invalid_argument(name_of_city.at(city) + " dont have a research station!");
        }
        if (board.get_research_station().count(_city) == 0){
        throw invalid_argument(name_of_city.at(_city) + " dont have a research station!");
        }
        if(city == _city){
            throw invalid_argument("illegal action: you can't fly to the city that you here at now");
        }
        city = _city;
        return *this;
    }

    Player& Player::build(){
        if(card.count(city) == 0){
            throw invalid_argument("You don't have a card of " + name_of_city.at(city));
        }
        board.build(city);
        card.erase(city);
        return *this;
    }
    
    Player& Player::discover_cure(Color color){
        if(board.get_research_station().count(city) == 0){
            throw std::invalid_argument{"illegal action: city "+name_of_city.at(city)+" has no research station!"};
        }
        int counter = 0;
        for(const auto& t : card){
            if(colors_of_cities.at(t) == color){
                counter++;
            }
        }
        if(cards_of_cure > counter){
            throw std::invalid_argument{"illegal action: you only have " + to_string(counter) +" " + colors.at(color) + " cards remaining " };
        }
        counter = 0;
        for(auto it = card.begin(); it != card.end(); counter++){
            if(counter == 4) { break; }
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

    Player& Player::treat(City _city){
        if(city != _city){
            throw invalid_argument("You are not in city " + name_of_city.at(_city));
        }
        if(board.disease_level[_city] == 0){
            throw invalid_argument("At " + name_of_city.at(_city) + " no have disease cubes");
        }
        if(board.get_discovered_cure().count(colors_of_cities.at(_city)) != 0){
            board.disease_level[_city] = 0;
        }
        else{board.disease_level[_city]--;}
        return *this;
    }

    Player& Player::take_card(City _city){
        card.insert(_city);
        return *this;
    }

    void Player::remove_cards(){
        card.clear();
    }
};