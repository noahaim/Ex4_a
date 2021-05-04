#include "doctest.h"
#include "Board.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
using namespace std;

using namespace pandemic;

TEST_CASE("check is_clean function")
{
    Board board;
    CHECK_FALSE(!board.is_clean());
	board[City::Kinshasa] = 3;
    CHECK_FALSE(board.is_clean());
}
TEST_CASE("check OperationsExpert player")
{
    Board board;
    OperationsExpert player{board, City::Miami};
    CHECK_THROWS(player.drive(City::Madrid));//no conection with madrid
    player.take_card(City::Miami);
    player.fly_charter(City::Jakarta);
    player.take_card(City::Delhi);
    player.fly_direct(City::Delhi);
    CHECK_THROWS(player.fly_direct(City::Milan));
    CHECK_THROWS(player.fly_shuttle(City::Moscow));
    player.build();//not need card
    CHECK_THROWS(player.treat(City::Moscow));
    

}
TEST_CASE("check Dispatcher player")
{
    Board board;
    Dispatcher player{board,City::Milan};
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.fly_direct(City::Delhi));
    player.take_card(City::Milan);
    player.fly_charter(City::Delhi);
    CHECK_THROWS(player.fly_direct(City::Milan));
    CHECK_THROWS(player.build());
    CHECK_THROWS(player.fly_direct(City::Miami));
    player.take_card(City::Delhi);
    player.build();
    player.fly_direct(City::Miami);
    CHECK_THROWS(player.treat(City::Miami));
}
TEST_CASE("check Scientist player")
{
    Board board;
    Scientist player{board, City::Miami,4};
    CHECK_THROWS(player.drive(City::Madrid));//no conection with madrid
    CHECK_THROWS(player.fly_direct(City::Delhi));
    player.take_card(City::Delhi);
    CHECK_THROWS(player.fly_direct(City::Milan));
    CHECK_THROWS(player.fly_charter(City::Milan));
    player.take_card(City::Miami);
    player.build();
    CHECK_THROWS(player.fly_charter(City::Milan));
    player.take_card(City::Miami);
    player.fly_charter(City::Milan);
    CHECK_THROWS(player.build());
    player.take_card(City::Milan);
    player.build();
    player.fly_shuttle(City::Miami);
    CHECK_THROWS(player.treat(City::Miami));
    player.take_card(City::Madrid);
    player.take_card(City::Milan);
    player.take_card(City::Paris);
    CHECK_THROWS(player.discover_cure(Color::Blue));
    player.take_card(City::Madrid);
    player.discover_cure(Color::Blue);
}
TEST_CASE("check Researcher player")
{
    Board board;
    Researcher player{board, City::Miami};
    CHECK_THROWS(player.drive(City::Madrid));//no conection with madrid
    CHECK_THROWS(player.fly_direct(City::Milan));
    CHECK_THROWS(player.fly_charter(City::Milan));
    player.take_card(City::Madrid);
    player.take_card(City::Milan);
    player.take_card(City::Paris);
    player.take_card(City::Madrid);
    CHECK_THROWS(player.discover_cure(Color::Blue));
    player.take_card(City::Montreal);
    player.discover_cure(Color::Blue);
    CHECK_THROWS(player.treat(City::Miami));    
}
TEST_CASE("check Medic player")
{
    Board board;
    Medic player{board,City::Milan};
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_charter(City::Madrid));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_shuttle(City::NewYork));
    CHECK_THROWS(player.build());
    player.take_card(City::Milan);
    player.build();
    CHECK_THROWS(player.fly_shuttle(City::NewYork));
    board[City::Milan]=3;
    player.treat(City::Miami);
    CHECK_THROWS(player.treat(City::Miami));

}
TEST_CASE("check Virologist player")
{
    Board board;
    Virologist player{board,City::Milan};
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_charter(City::Madrid));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_shuttle(City::NewYork));
    CHECK_THROWS(player.treat(City::Milan));
    board[City::Milan]=1;
    player.take_card(City::Milan);
    player.fly_charter(City::Osaka);
    player.treat(City::Milan);
    CHECK_THROWS(player.treat(City::Milan));
    CHECK_THROWS(player.build());
    
}
TEST_CASE("check GeneSplicer player")
{
    Board board;
    GeneSplicer player{board,City::Milan};
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.fly_charter(City::Madrid));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_shuttle(City::NewYork));
    CHECK_THROWS(player.treat(City::Milan));
    player.take_card(City::Madrid);
    player.take_card(City::Milan);
    player.take_card(City::Paris);
    player.take_card(City::Madrid);
    player.take_card(City::Miami);
    player.discover_cure(Color::Black);
    CHECK_THROWS(player.discover_cure(Color::Red));
    CHECK_THROWS(player.build());
}
TEST_CASE("check FieldDoctor player")
{
    Board board;
    FieldDoctor player{board,City::Milan};
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.fly_charter(City::Madrid));
    CHECK_THROWS(player.fly_direct(City::Madrid));
    CHECK_THROWS(player.fly_shuttle(City::NewYork));
    CHECK_THROWS(player.treat(City::Milan));
    board[City::Milan]=1;
    player.drive(City::Essen);
    player.treat(City::Milan);
    CHECK_THROWS(player.treat(City::Milan));
    CHECK_THROWS(player.build());
}
