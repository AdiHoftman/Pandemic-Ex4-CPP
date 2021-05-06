#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic{

    Player& OperationsExpert::build(){
        board.build(city);
        return *this;
    }

};