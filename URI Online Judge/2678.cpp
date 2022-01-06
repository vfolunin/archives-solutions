#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    static string letters = "ABCDEFGHIJKLMNOPRSTUVWXY";
    static string digits  = "222333444555666777888999";

    for (char c : s) {
        if (isalpha(c))
            cout << digits[letters.find(toupper(c))];
        else if (isdigit(c) || c == '*' || c == '#')
            cout << c;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}