#include "Board.hpp"

using namespace pandemic;
namespace pandemic{
       int& Board::operator[](City c){
           return x;
       }
       std::ostream& operator<< (std::ostream& os, const Board& b){
           return os;
       } 
       bool Board::is_clean()
       {
           return true;
       }
       void Board::remove_cures(){

       }
}


