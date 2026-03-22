#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, symbols;
    cin >> s >> symbols;

    unordered_set<char> symbolSet(symbols.begin(), symbols.end());

    for (int len = symbols.size(); len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (unordered_set<char>(s.begin() + l, s.begin() + r + 1) == symbolSet) {
                cout << len;
                return 0;
            }
        }
    }

    cout << 0;
}