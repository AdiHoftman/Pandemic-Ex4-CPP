#include "Board.hpp"

using namespace std;

namespace pandemic{ 

    int &Board::operator[](City city){
        return this->disease_level[city];
    }

    std::ostream& operator<<(ostream& out, Board& board){
        for(auto& level : board.disease_level){
            out << "[" << name_of_city.at(level.first) << ", " << level.second << "]" << endl;
        }
        for(size_t i = 0; i < 4; i++){
            out << "Color of the discovered cure is: " << colors.at(i);
        }
        for(const auto& station : board.research_station){
            out << "Research stations that build for now are: " << name_of_city.at(station) << endl;
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

    // bool Board::is_there_a_research_station(City city) {
    //     return (this->research_station.count(city) != 0);
    // }


    void Board::build(City city){
        this->research_station.insert(city);
    }

    // Color Board::get_color(City city){
    //     return colors_of_cities.at(city);
    // }

    bool& Board::is_cure(Color color){
        if(color == Color::Black){return c_black;}
        if(color == Color::Blue){return c_blue;}
        if(color == Color::Red){return c_red;}
        return c_yellow;
    }

    void Board::set_cure(Color color){
        if(color == Color::Black){c_black = true;}
        if(color == Color::Blue){c_blue = true;}
        if(color == Color::Red){c_red = true;}
        if(color == Color::Yellow){c_yellow = true;}
    }

    // bool Board::is_cure_discoverd(City city) {
    //     return cure[get_color(city)];
    // }
};