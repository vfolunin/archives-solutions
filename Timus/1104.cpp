#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int digitSum = 0, maxDigit = 0;
    for (char c : s) {
        int digit = isdigit(c) ? c - '0' : c - 'A' + 10;
        digitSum += digit;
        maxDigit = max(maxDigit, digit);
    }

    for (int base = max(maxDigit + 1, 2); base <= 36; base++) {
        if (digitSum % (base - 1) == 0) {
            cout << base;
            return 0;
        }
    }

    cout << "No solution.";
}