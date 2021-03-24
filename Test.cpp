#include"doctest.h"
#include"Board.hpp"
#include"Direction.hpp"
using namespace ariel;

TEST_CASE("Good code"){
    ariel::Board board;
    board.post(100,200,Direction::Horizontal,"abcd");
    CHECK(board.read(99,201,Direction::Vertical,3)=="_b_");
    CHECK(board.read(100,203,Direction::Horizontal,3)=="d__");
    CHECK(board.read(100,200,Direction::Horizontal,1)=="a");
    CHECK(board.read(100,201,Direction::Horizontal,1)=="b");
    CHECK(board.read(100,202,Direction::Horizontal,1)=="c");
    CHECK(board.read(100,203,Direction::Horizontal,1)=="d");
    CHECK(board.read(100,200,Direction::Horizontal,6)=="abcd__");

    board.post(100,300,Direction::Horizontal,"first_massage");
    CHECK(board.read(100,300,Direction::Horizontal,13)=="first_massage");
    CHECK(board.read(100,301,Direction::Horizontal,5)=="irst_");
    CHECK(board.read(100,306,Direction::Horizontal,7)=="massage");
    CHECK(board.read(100,299,Direction::Horizontal,6)=="_first");
    CHECK(board.read(100,297,Direction::Horizontal,8)=="___first");
    CHECK(board.read(100,30,Direction::Horizontal,7)=="massage");

    board.post(100,100,Direction::Vertical,"two_massage_2");
     CHECK(board.read(100,100,Direction::Vertical,13)=="two_massage_2");
     CHECK(board.read(99,100,Direction::Vertical,4)=="_two");
     CHECK(board.read(100,100,Direction::Vertical,3)=="two");
     CHECK(board.read(100,100,Direction::Vertical,4)=="two_");
     CHECK(board.read(104,100,Direction::Vertical,7)=="massage");
     CHECK(board.read(103,100,Direction::Vertical,9)=="_massage_");
     CHECK(board.read(103,100,Direction::Vertical,8)=="_massage");
     CHECK(board.read(111,100,Direction::Vertical,3)=="_2_");
     CHECK(board.read(112,100,Direction::Vertical,1)=="2");
     CHECK(board.read(112,100,Direction::Vertical,2)=="2_");
     CHECK(board.read(112,100,Direction::Vertical,3)=="2__");
     CHECK(board.read(99,100,Direction::Horizontal,5)=="_____");
     CHECK(board.read(100,100,Direction::Horizontal,5)=="t____");
}
TEST_CASE("Bad code"){
    ariel::Board board;
    board.post(100,150,Direction::Horizontal,"Error_massage");
    CHECK_THROWS(board.read(100,150,Direction::Horizontal,0));
    CHECK_THROWS(board.read(100,152,Direction::Horizontal,0));
    board.post(100,250,Direction::Vertical,"Error!!");
    CHECK_THROWS(board.read(100,250,Direction::Vertical,0));
    CHECK_THROWS(board.read(101,250,Direction::Vertical,0));
}    
