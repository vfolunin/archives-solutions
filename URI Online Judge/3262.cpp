#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int findDigit(vector<string> &number, int offset) {
    static vector<string> digits = {
        "***   * *** *** * * *** *** *** *** ***",
        "* *   *   *   * * * *   *     * * * * *",
        "* *   * *** *** *** *** ***   * *** ***",
        "* *   * *     *   *   * * *   * * *   *",
        "***   * *** ***   * *** ***   * *** ***"
    };

    for (int digit = 0; digit < 10; digit++) {
        int ok = 1;
        for (int row = 0; ok && row < 5; row++)
            ok &= number[row].substr(offset, 3) == digits[row].substr(digit * 4, 3);
        if (ok)
            return digit;
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> number(5);
    for (string &row : number)
        getline(cin, row);

    int remainder = 0;
    for (int offset = 0; offset < number[0].size(); offset += 4) {
        int digit = findDigit(number, offset);
        if (digit == -1) {
            remainder = 1;
            break;
        }
        remainder = (remainder * 10 + digit) % 6;
    }

    cout << (remainder ? "BOOM!!\n" : "BEER!!\n");
}