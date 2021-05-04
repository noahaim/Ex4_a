#include "Player.hpp"
namespace pandemic{
            Player::Player(){
                
            }
            Player::Player(Board board,City c){

            }
            Player& Player::drive(City c){
                return *this;
            }
            Player& Player::fly_direct(City c){
                return *this;
            }
            Player& Player::fly_charter(City c){
                return *this;
            }
            Player& Player::fly_shuttle(City c){
                return *this;
            }
            Player& Player::build(){
                return *this;
            }
            bool Player::discover_cure(Color c){
                return true;
            }
            Player& Player::treat(City c){
                return *this;
            }
            std::string Player::role(){
                return "";
            }
            Player& Player::take_card(City c){
                return *this;
            }

}