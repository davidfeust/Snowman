//
// Created by david on 11/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <cmath>

int create_code();

using namespace std;

/**
 * Simple main, example of snowman function.
 * The main takes number for the user, and prints the appropriate snowman.
 * Input of 0 will generate random snowman.
 * Input of -1 will stop the program.
 */
int main() {
    cout << "Stop the program by: -1" << endl;
    cout << "Generate random snowman by: 0" << endl;
    int n = 0;
    while (true) {
        cout << "Enter snowman code number: ";
        cin >> n;
        if (n == 0) {
            cout << ariel::snowman(create_code()) << endl;
        } else if (n == -1) {
            break;
        } else {
            try {
                cout << ariel::snowman(n) << endl;
            } catch (exception &e) {
                cerr << "caught exception: " << e.what() << endl;
            }
        }
    }
    return 0;
}

/**
 * Return number from the digits of the giving array, with size n.
 * @param arr array with one digit in each cell.
 * @param n size of arr
 * @return number
 */
int arr_to_number(const int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i] * (int) pow(10, i);
    }
    return ans;
}

/**
 * Generates a valid random code number by snowman code format.
 * @return number code.
 */
int create_code() {
    int nums[8];
    for (int i = 0; i < 8; ++i) {
        int r = (rand() % 4) + 1;
        nums[i] = r;
    }
    return arr_to_number(nums, 8);
}