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

    static vector<string> codes = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    static vector<int> vals = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    if (isdigit(s[0])) {
        int n = stoi(s);
        for (int i = vals.size() - 1; i >= 0; i--) {
            while (n >= vals[i]) {
                n -= vals[i];
                cout << codes[i];
            }
        }
    } else {
        int n = 0;
        for (int i = vals.size() - 1, from = 0; i >= 0; i--) {
            while (s.substr(from, codes[i].size()) == codes[i]) {
                n += vals[i];
                from += codes[i].size();
            }
        }
        cout << n;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}