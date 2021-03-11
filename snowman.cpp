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
    // Checks if the number is valid
    const int big_number = 99999999;
    const int small_number = 10000000;
    if (num > big_number) {
        throw out_of_range("Code number is invalid!\n More then 8 digits!");
    }
    if (num < small_number) {
        throw out_of_range("Code number is invalid!\n Less then 8 digits!");
    }
    if (is_invalid(num)) {
        throw out_of_range("Invalid code '" + to_string(num) + "'");
    }

    // All possibles elements for every part in the snowman
    const std::array<string, 4> hat = {"       \n _===_ \n", "  ___  \n ..... \n", "   _   \n  /_\\  \n",
                                       "  ___  \n (_*_) \n"};
    const std::array<string, 4> nose = {",", ".", "_", " "};
    const std::array<string, 4> eye = {".", "o", "O", "-"};
    const std::array<string, 4> left_arm_up = {" ", "\\", " ", " "};
    const std::array<string, 4> left_arm_down = {"<", " ", "/", " "};
    const std::array<string, 4> right_arm_up = {" ", "/", " ", " "};
    const std::array<string, 4> right_arm_down = {">", " ", "\\", " "};
    const std::array<string, 4> torso = {" : ", "] [", "> <", "   "};
    const std::array<string, 4> base = {" : ", "\" \"", "___", "   "};

    // Inserts the code number into array
    const int size = 8;
    array<int, size> code{};
    for (int i = 0; i < size; ++i) {
        const int div = 10;
        code.at(size - 1 - i) = (num % div) - 1;
        num /= div;
    }

    // Takes the appropriate code for each part of the snowman, in order: HNLRXYTB
    int index_code = 0;
    const int h = code.at(index_code++);
    const int n = code.at(index_code++);
    const int l = code.at(index_code++);
    const int r = code.at(index_code++);
    const int x_up = code.at(index_code);
    const int x_down = code.at(index_code++);
    const int y_up = code.at(index_code);
    const int y_down = code.at(index_code++);
    const int t = code.at(index_code++);
    const int b = code.at(index_code);

    // Assembles the snowman
    string ans = hat.at(h);
    ans += left_arm_up.at(x_up) + "(" + eye.at(l) + nose.at(n) + eye.at(r) + ")" + right_arm_up.at(y_up) + "\n";
    ans += left_arm_down.at(x_down) + "(" + torso.at(t) + ")" + right_arm_down.at(y_down) + "\n";
    ans += " (" + base.at(b) + ") \n";

    return ans;
}

/**
 * Checks all the digits in the number, ans returns true iff all the digits is between 1 to 4.
 * @param num snowman code
 * @return true iff all the digits is between 1 to 4, false otherwise.
 */
bool is_invalid(int num) {
    while (num > 0) {
        const int div = 10;
        int digit = num % div;
        if (digit == 0 || digit > 4) {
            return true;
        }
        num /= div;
    }
    return false;
}