#include <array>
#include "snowman.hpp"

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
    const int big_number = 99999999;
    const int small_number = 10000000;
    if (num > big_number) {
        throw invalid_argument("Code number is invalid!\n More then 8 digits!");
    }
    if (num < small_number) {
        throw invalid_argument("Code number is invalid!\n Less then 8 digits!");
    }
    if (is_invalid(num)) {
        throw invalid_argument("Invalid code '" + to_string(num) + "'");
    }

    const std::array<string, 4> hat = {"       \n _===_ \n", "  ___  \n ..... \n", "   _   \n  /_\\  \n", "  ___  \n (_*_) \n"};
    const std::array<string, 4> nose = {",", ".", "_", " "};
    const std::array<string, 4> eye = {".", "o", "O", "-"};
    const std::array<string, 4> left_arm_up = {" ", "\\", " ", " "};
    const std::array<string, 4> left_arm_down = {"<", " ", "/", " "};
    const std::array<string, 4> right_arm_up = {" ", "/", " ", " "};
    const std::array<string, 4> right_arm_down = {">", " ", "\\", " "};
    const std::array<string, 4> torso = {" : ", "] [", "> <", "   "};
    const std::array<string, 4> base = {" : ", "\" \"", "___", "   "};

    string ans = string("");
    array<int, 8> code{};
    for (int i = 0; i < 8; ++i) {
        code[7 - i] = (num % 10) - 1;
        num /= 10;
    }

    ans += hat[code[0]];

    ans += left_arm_up[code[4]];
    ans += "(" + eye[code[2]] + nose[code[1]] + eye[code[3]] + ")";
    ans += right_arm_up[code[5]] + "\n";

    ans += left_arm_down[code[4]];
    ans += "(" + torso[code[6]] + ")";
    ans += right_arm_down[code[5]] + "\n";
    ans += " (" + base[code[7]] + ") \n";
    return ans;
}

/**
 * Checks all the digits in the number, ans returns true iff all the digits is between 1 to 4.
 * @param num snowman code
 * @return true iff all the digits is between 1 to 4, false otherwise.
 */
bool is_invalid(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || digit > 4) {
            return true;
        }
        num /= 10;
    }
    return false;
}