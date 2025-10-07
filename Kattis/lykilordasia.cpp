#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPassword(string &s) {
    bool hasLetter = 0, hasDigit = 0;
    for (char c : s) {
        hasLetter |= (bool)isalpha(c);
        hasDigit |= (bool)isdigit(c);
    }
    return hasLetter && hasDigit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    for (int i = 0; cin >> s; i++) {
        if (i)
            cout << " ";

        if (isPassword(s))
            cout << string(s.size(), '*');
        else
            cout << s;
    }
}