#include "Board.hpp"

using namespace std;

namespace pandemic{ 

    // get the level of disease at cities.
    int &Board::operator[](City city){
        return this->disease_level[city];
    }

    std::ostream& operator<<(ostream& out, Board& board){
        // print the level of disease at cities.
        for(auto& level : board.disease_level){
            out << "[" << name_of_city.at(level.first) << ", " << level.second << "]" << endl;
        }
        //print the color of the cure that discovered.
        for(size_t i = 0; i < 4; i++){
            out << "Color of the discovered cure is: " << colors.at(i);
        }
        //print the research stations at cities.
        for(const auto& station : board.research_station){
            out << "Research stations that build for now are: " << name_of_city.at(station) << endl;
        }
        return out;
    }

    // check if the board of the game is clean, if the disease level of all the cities is 0.
    bool Board::is_clean(){
        for(auto& city : disease_level){
            if(city.second != 0){
                return false;
            }
        }
        return true;
    }

    // remove the cures that discovered.
    void Board::remove_cures(){
        discovered_cure.clear();
    }

    // remove the research satations that built.
    void Board::remove_stations(){
        this->research_station.clear();
    }

    // build a research station.
    void Board::build(City city){
        this->research_station.insert(city);
    }

    // discover a cure.
    void Board::set_cure(Color color){
        this->discovered_cure.insert(color);
    }
};