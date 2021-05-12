#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic{

    // can build a research station at any city that he located it, without a card of the specific city.
    Player& OperationsExpert::build(){
        board.build(city);
        return *this;
    }

};