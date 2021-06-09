#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int toDec(string &s) {
    static map<string, int> codes = {
        {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
        {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
        {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}
    };

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && codes.count(string() + s[i] + s[i + 1])) {
            res += codes[string() + s[i] + s[i + 1]];
            i++;
        } else {
            res += codes[string(1, s[i])];
        }
    }
    return res;
}

string toRoman(int n) {
    static map<int, string> codes = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
        {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
        {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
    };

    string res;
    for (auto it = codes.rbegin(); it != codes.rend(); it++) {
        while (n >= it->first) {
            n -= it->first;
            res += it->second;
        }
    }
    return res;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int n = toDec(s);
    if (0 < n && n < 4000 && toRoman(n) == s)
        cout << n << "\n";
    else
        cout << "This is not a valid number\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}