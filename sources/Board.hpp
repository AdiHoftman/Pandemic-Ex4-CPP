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
            set<Color> discovered_cure;   
            set<City> research_station;

        public:
            Board(){}
            int &operator [](City city);
            friend std::ostream& operator<<(ostream& out, Board& board);
            bool is_clean();
            void remove_cures();
            void remove_stations();
            void build(City city);
            void set_cure(Color color);

            set<City> &get_research_station(){
                return research_station;
            }

            set<Color> &get_discovered_cure(){
                return discovered_cure;
            }

            set<Color> &set_discovered_cure(Color color){
                discovered_cure.insert(color);
                return discovered_cure;
            }
    };

};
