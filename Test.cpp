/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: David Feust
 * 
 * Date: 2021-02
 */

#include <cmath>
#include <string>
#include "doctest.h"

#include "snowman.hpp"

using namespace ariel;

using namespace std;

int arr_to_number(const int arr[], int n);
int create_code();

/*
 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

 HNLRXYTB:
 H - Hat
 N - Nose/Mouth
 L - Left Eye
 R - Right Eye
 X - Left Arm
 Y - Right Arm
 T - Torso
 B - Base
 */


TEST_CASE ("Good snowman code") {
            CHECK(snowman(43211234) == string("  ___  \n"
                                              " (_*_) \n"
                                              " (o_.)/\n"
                                              "<(> <) \n"
                                              " (   ) \n"));

            CHECK(snowman(31433313) == string("   _   \n"
                                              "  /_\\  \n"
                                              " (-,O) \n"
                                              "/( : )\\\n"
                                              " (___) \n"));

            CHECK(snowman(33232124) == string("   _   \n"
                                              "  /_\\  \n"
                                              "\\(o_O) \n"
                                              " (] [)>\n"
                                              " (   ) \n"));
}

TEST_CASE ("More test") {

            CHECK(snowman(22222222) == string("  ___  \n"
                                              " ..... \n"
                                              "\\(o.o)/\n"
                                              " (] [) \n"
                                              " (\" \") \n"));

            CHECK(snowman(33333333) == string("   _   \n"
                                              "  /_\\  \n"
                                              " (O_O) \n"
                                              "/(> <)\\\n"
                                              " (___) \n"));

            CHECK(snowman(44444444) == string("  ___  \n"
                                              " (_*_) \n"
                                              " (- -) \n"
                                              " (   ) \n"
                                              " (   ) \n"));

            CHECK(snowman(14114444) == string("       \n"
                                              " _===_ \n"
                                              " (. .) \n"
                                              " (   ) \n"
                                              " (   ) \n"));

            CHECK(snowman(12344321) == string("       \n"
                                              " _===_ \n"
                                              " (O.-) \n"
                                              " (] [)\\\n"
                                              " ( : ) \n"));

            CHECK(snowman(44332211) == string("  ___  \n"
                                              " (_*_) \n"
                                              "\\(O O)/\n"
                                              " ( : ) \n"
                                              " ( : ) \n"));

            CHECK(snowman(11223344) == string("       \n"
                                              " _===_ \n"
                                              " (o,o) \n"
                                              "/(   )\\\n"
                                              " (   ) \n"));

            CHECK(snowman(12222212) == string("       \n"
                                              " _===_ \n"
                                              "\\(o.o)/\n"
                                              " ( : ) \n"
                                              " (\" \") \n"));
}


//TEST_CASE("Bad snowman code") {
//            CHECK_THROWS(snowman(555));
//            CHECK_THROWS(snowman(222222222)); // 9 digits
//            CHECK_THROWS(snowman(2222222)); // 7 digits
//            CHECK_THROWS(snowman(123321)); // short number
//            CHECK_THROWS(snowman(11118111)); // invalid digit (8)
//            CHECK_THROWS(snowman(-31433313)); // negative number
//            CHECK_THROWS(snowman(0)); // zero
//}

//
//TEST_CASE ("More then 8 digits") {
//    for (int i = 0; i < 20; ++i) {
//        int num = 10000000;
//        int random = (int) rand();
//        num += random;
//        CHECK_THROWS(snowman(num));
//    }
//}


TEST_CASE("Invalid digit") {
    for (int i = 5; i <= 10; ++i) {
        for (int j = 0; j < 8; ++j) {
            int num[] = {1, 1, 1, 1, 1, 1, 1, 1};
            if (i == 10) {
                num[j] = 0;
            } else {
                num[j] = i;
            }
            int n = arr_to_number(num, 8);
            CHECK_THROWS(snowman(n));
        }
    }
}

TEST_CASE ("Negative number") {
    for (int i = 0; i < 20; ++i) {
        int n = create_code();
                CHECK_NOTHROW(snowman(n));
                CHECK_THROWS(snowman(n * -1));
    }
}

TEST_CASE ("Number of lines and chars") {
    for (int k = 0; k < 20; ++k) {
        string s = snowman(create_code());
        int counter = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '\n') counter++;
        }
                CHECK(counter == 5);
        if (counter != 4) return;
        for (int i = 0; i < 4; ++i) {
            int num_of_chars = 0;
            for (int j = 0; s[j] != '\n'; ++j) {
                num_of_chars++;
            }
                    CHECK(num_of_chars == 7);
        }
    }
}


int arr_to_number(const int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i] * (int) pow(10, i);
    }
    return ans;
}


int create_code() {
    int nums[8] = {};
    for (int i = 0; i < 8; ++i) {
        int r = (rand() % 4) + 1;
        nums[i] = r;
    }
    return arr_to_number(nums, 8);
}
