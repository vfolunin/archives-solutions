#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    static vector<string> soundex = { "AEHIOUWY", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R" };

    string word;
    if (!(cin >> word))
        return 0;

    vector<int> digits;
    for (char letter : word) {
        int digit = 0;
        while (soundex[digit].find(letter) == -1)
            digit++;
        if (digits.empty() || digits.back() != digit)
            digits.push_back(digit);
    }

    for (int digit : digits)
        if (digit)
            cout << digit;
    cout << "\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}