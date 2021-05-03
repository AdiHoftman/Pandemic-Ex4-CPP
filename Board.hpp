#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic{
    class Board{

        friend class Player;
        public:
            map<City, int> disease_level;
            set<City> research_station;
            bool cure[4] = {0};
            bool c_black, c_blue, c_red, c_yellow;

        public:
            Board(){}
            int &operator [](City city);
            friend std::ostream& operator<<(ostream& out, Board& board);
            bool is_clean();
            void remove_cures();
            std::string colors(int color);
            void build(City city);
    };

};
