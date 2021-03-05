#include <iostream>
#include "snowman.hpp"
#include <cmath>

using namespace std;
//using namespace ariel;

/*
 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

HNLRXYTB
*/

string ariel::snowman(int num) {
//    string ans = " HHHHH \n"
//                 " HHHHH \n"
//                 "X(LNR)Y\n"
//                 "X(TTT)Y\n"
//                 " (BBB) ";
//    for (int i = 7; i >= 0; --i) {
//        int digit = (num / (pow(10, i)));
//        num = num % (int) (pow(10, i));
//        ans.replace(0, 16, shapes[7 - i][digit - 1]);
//        break;
//
////        ans += ariel::shapes[7 - i][digit - 1];
//    }
//
    return "_===_\n(.,.)\n( : )\n( : )";
//    return ans;

}


int main() {
//    std::cout << "Hello, World!" << std::endl;
    std::cout << ariel::snowman(43211234);
    std::cout << std::endl<< std::endl;
//    std::cout << ariel::snowman(12345678);
    return 0;
}

