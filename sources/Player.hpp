#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic{
    
    class Player{
        protected:
            std::set<City> card;
            Board& board;
            City city;
            std::string role_of;

        public:
            Player(Board& b, City c, std::string r) : board(b), city(c), role_of(r){}
            virtual Player& take_card(City _city);
            virtual Player& drive(City _city);
            virtual Player& fly_direct(City _city);
            virtual Player& fly_charter(City _city);
            virtual Player& fly_shuttle(City _city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City _city);
            virtual std::string role(){return role_of;}
        };

};