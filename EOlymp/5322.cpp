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

    if (s.size() % 4)
        s = string(4 - s.size() % 4, '0') + s;

    const string DIGITS = "0123456789ABCDEF";

    for (int i = 0, value = 0; i < s.size(); i++, value *= 2) {
        value += s[i] - '0';
        if (i % 4 == 3) {
            cout << DIGITS[value];
            value = 0;
        }
    }
}