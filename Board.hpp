#pragma once
#include <string>
#include "City.hpp"
namespace pandemic{
    class Board{
        int x;
        public:
            int& operator[](City c);
            friend std::ostream& operator<< (std::ostream& os, const Board& b);
            bool is_clean();
            void remove_cures();
    };
}