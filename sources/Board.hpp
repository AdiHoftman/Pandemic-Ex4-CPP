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

            // return the cities that have a research station.
            set<City> &get_research_station(){
                return research_station;
            }

            // return the cures that discovered.
            set<Color> &get_discovered_cure(){
                return discovered_cure;
            }

            // discover a cure and return the cure that discovered.
            set<Color> &set_discovered_cure(Color color){
                discovered_cure.insert(color);
                return discovered_cure;
            }
    };

};
