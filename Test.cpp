#include <iostream>
#include "doctest.h"   
#include <stdexcept>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "Medic.hpp"
#include "GeneSplicer.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <string>
using namespace std; //used to include functions such as memcpy..

TEST_CASE("operator []"){
	Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	board[City::Algiers] = 4;      // put 4 yellow disease cubes in Algiers.
	board[City::Algiers] = 3;      // change number of disease cubes in Algiers to 3.
	board[City::London] = 2;    // put 2 yellow disease cubes in London
	board[City::Madrid] = 2; // put 2 red disease cube in Madrid
	board[City::BuenosAires] = 1; 
    CHECK_NOTHROW(board[City::Algiers] = 3);
    CHECK_NE(board[City::Algiers], 4);
    CHECK(board[City::London] == 2);
    CHECK(board[City::Madrid] == 2);
    CHECK(board[City::BuenosAires] == 1);
    board[City::Algiers] = 1;
    board[City::Madrid] = 0;
    CHECK(board[City::Algiers] != 3);
    CHECK(board[City::Madrid] == 0);
    CHECK(board[City::Mumbai] == 0);
    board[City::Mumbai] = 2;
    CHECK(board[City::Mumbai] != 0);
    CHECK(board[City::Mumbai] == 2);
    board[City::NewYork] = 4;
    CHECK(board[City::NewYork] == 4);
    board[City::NewYork] = 1;
    CHECK(board[City::NewYork] == 1);
    board[City::NewYork] = 0;
    CHECK(board[City::NewYork] == 0);
}

TEST_CASE("OprationsExpert"){
    Board board;
    OperationsExpert player{board, LosAngeles};
    player.build();
    player.take_card(City::Chicago).take_card(City::Washington).take_card(City::Paris); 
    player.fly_direct(City::Washington);
    player.build();
    player.take_card(Washington).take_card(SanFrancisco).take_card(London).take_card(StPetersburg);
    CHECK_THROWS(player.fly_shuttle(City::StPetersburg));
    player.fly_direct(London);
    player.build();
    board[City::London] = 5;
    board.remove_cures();
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.treat(City::London));
}

TEST_CASE("Dispatcher"){
    Board board;
    Dispatcher player{board, City::Sydney};
    CHECK_THROWS(player.build());
    player.take_card(Sydney);
    CHECK_NOTHROW(player.build());
    player.take_card(Santiago).take_card(Seoul).take_card(Shanghai);
    board.build(City::SaoPaulo);
    player.fly_direct(SaoPaulo);
    CHECK_THROWS(player.build());
    player.take_card(SaoPaulo);
    board[City::SaoPaulo] = 3;
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player.treat(SaoPaulo));
    CHECK(board[City::SaoPaulo] == 2);
}

TEST_CASE("Scientist"){
    Board board;
    Scientist player{board, City::Santiago, 1};
    player.take_card(Santiago);
    player.build();
    CHECK_THROWS(player.discover_cure(Color::Yellow)); //ilegall action: Don't have cards.
    //board[City::Santiago] = 1;
    player.take_card(City::Bogota);
    CHECK_NOTHROW(player.discover_cure(Color::Yellow)); // llegal action: Have 1 card.
}

