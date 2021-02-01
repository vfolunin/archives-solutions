#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static string digits = "22233344455566677778889999";

    for (char c : s) {
        if (isupper(c))
            cout << digits[letters.find(c)];
        else
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