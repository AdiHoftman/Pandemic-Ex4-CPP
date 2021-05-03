#include "Board.hpp"

using namespace std;

namespace pandemic{ 

    int &Board::operator[](City city){
        return this->disease_level[city];
    }

    std::ostream& operator<<(ostream& out, Board& board){
        for(auto& level : board.disease_level){
            out << "[" << cities.at(level.first) << ", " << level.second << "]" << endl;
        }
        for(size_t i = 0; i < 4; i++){
            out << "Color of the discovered cure is: " << colors.at(i);
        }
        for(const auto& station : board.research_station){
            out << "Research stations that build for now are: " << cities.at(station) << endl;
        }
        
        return out;
    }

    bool Board::is_clean(){
        for(auto& city : disease_level){
            if(city.second != 0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        c_black = false;
        c_blue = false;
        c_red = false;
        c_yellow = false;
    }

    void Board::build(City city){
        this->research_station.insert(city);
    }
};