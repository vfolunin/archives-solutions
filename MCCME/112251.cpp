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

    int value;
    cin >> value;

    bool isNegative = 0;
    if (value < 0) {
        value = -value;
        isNegative = 1;
    }

    vector<int> digits;
    for (; value; value /= 3)
        digits.push_back(value % 3);
    if (digits.empty())
        digits.push_back(0);

    for (int i = 0, carry = 0; i < digits.size() || carry; i++) {
        if (i == digits.size())
            digits.emplace_back();

        digits[i] += carry;
        carry = digits[i] / 3;
        digits[i] %= 3;

        if (digits[i] == 2) {
            digits[i] = -1;
            carry++;
        }
    }

    reverse(digits.begin(), digits.end());

    if (isNegative)
        for (int &digit : digits)
            digit = -digit;

    for (int &digit : digits) {
        if (digit >= 0)
            cout << digit;
        else
            cout << "#";
    }
}