#include <iostream>
#include "snowman.hpp"
#include <cmath>

using namespace std;
using namespace ariel;
bool is_invalid(int num);


/*
 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

HNLRXYTB
*/
/**
 * Returns string of snowman by the pattern of the code number
 * @param num code number of snowman
 * @return string of snowman by the code number
 */
string ariel::snowman(int num) {
    if (num > 99999999 || num < 10000000) {
        throw invalid_argument("the args not good!");
    }
    if (is_invalid(num)) {
        throw invalid_argument("the args not good!");
    }
    const string hat[] = {"       \n _===_ \n", "  ___  \n ..... \n", "   _   \n  /_\\  \n", "  ___  \n (_*_) \n"};
    const string nose[] = {",", ".", "_", " "};
    const string eye[] = {".", "o", "O", "-"};
    const string left_arm[] = {"<", "\\", "/", " "};
    const string right_arm[] = {">", "/", "\\", " "};
    const string torso[] = {" : ", "] [", "> <", "   "};
    const string base[] = {" : ", "\" \"", "___", "   "};

    string ans = string("");
    int code[8];
    for (int i = 0; i < 8; ++i) {
        code[7 - i] = (num % 10) - 1;
        num /= 10;
    }
    ans += hat[code[0]];
    if (code[4] == 1) {
        ans += left_arm[1];
    } else {
        ans += " ";
    }
    ans += "(" + eye[code[2]] + nose[code[1]] + eye[code[3]] + ")";
    if (code[5] == 1) {
        ans += right_arm[1] + "\n";
    } else {
        ans += " \n";
    }

    if (code[4] != 1) {
        ans += left_arm[code[4]];
    } else {
        ans += " ";
    }
    ans += "(" + torso[code[6]] + ")";
    if (code[5] != 1) {
        ans += right_arm[code[5]] + "\n";
    } else {
        ans += " \n";
    }
    ans += " (" + base[code[7]] + ") \n";
    return ans;
}

//
//int main() {
////    std::cout << "Hello, World!" << std::endl;
//    std::cout << ariel::snowman(43211234);
//    std::cout << std::endl << std::endl;
////    std::cout << ariel::snowman(12345678);
//    return 0;
//}

bool is_invalid(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || digit > 4) return true;
        num /= 10;
    }
    return false;
}