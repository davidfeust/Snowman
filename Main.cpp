//
// Created by david on 11/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <cmath>

int create_code();

using namespace std;

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

int arr_to_number(const int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i] * (int) pow(10, i);
    }
    return ans;
}

int create_code() {
    int nums[8];
    for (int i = 0; i < 8; ++i) {
        int r = (rand() % 4) + 1;
        nums[i] = r;
    }
    return arr_to_number(nums, 8);
}