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

#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;

#include <string>

using namespace std;

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
            CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));


            CHECK(snowman(43211234) == string(" ___ \n"
                                              "(_*_)\n"
                                              " (o_.)/\n"
                                              "<(> <) \n"));

            CHECK(snowman(31433313) == string("  _  \n"
                                              " /_\\ \n"
                                              " (-,O) \n"
                                              "/( : )\\\n"
                                              " (___)"));

            CHECK(snowman(33232124) == string("   _\n"
                                              "  /_\\\n"
                                              "\\(o_O) \n"
                                              " (] [)>\n"
                                              " (   )"));


}

TEST_CASE ("Bad snowman code") {
            CHECK_THROWS(snowman(555));
            CHECK_THROWS(snowman(222222222)); // 9 digits
            CHECK_THROWS(snowman(2222222)); // 7 digits
            CHECK_THROWS(snowman(123321)); // short number
            CHECK_THROWS(snowman(11118111)); // invalid digit (8)
            CHECK_THROWS(snowman(-31433313)); // negative number
            CHECK_THROWS(snowman(0)); // zero
}

TEST_CASE ("More test") {
            CHECK(snowman(11111111) == string("_===_\n<(.,.)>\n<( : )>\n( : )"));

            CHECK(snowman(22222222) == string(" ___ \n"
                                              ".....\n"
                                              "\\(o.o)/\n"
                                              "\\(] [)/\n"
                                              "(\" \")"));

            CHECK(snowman(33333333) == string("  _  \n"
                                              " /_\\ \n"
                                              "/(O_O)\\\n"
                                              "/(> <)\\\n"
                                              " (___)"));

            CHECK(snowman(44444444) == string(" ___ \n"
                                              "(_*_)\n"
                                              " (- -) \n"
                                              " (   ) \n"
                                              " (   )"));

            CHECK(snowman(14114444) == string("_===_\n"
                                              " (. .) \n"
                                              " (   ) \n"
                                              " (   )"));

            CHECK(snowman(12344321) == string("_===_\n"
                                              " (O.-) \n"
                                              " (] [)\\\n"
                                              " ( : )"));

            CHECK(snowman(44332211) == string(" ___ \n"
                                              "(_*_)\n"
                                              " (O O) \n"
                                              "\\( : )/\n"
                                              " ( : )"));

            CHECK(snowman(11223344) == string("_===_\n"
                                              " (o,o) \n"
                                              "/(   )\\\n"
                                              " (   )"));

            CHECK(snowman(12222212) == string(" _===_\n"
                                              "\\(o.o)/\n"
                                              " ( : ) \n"
                                              " (\" \")"));

}

