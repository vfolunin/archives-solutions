#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "*")
        return 0;

    for (int d = 1; d < s.size(); d++) {
        set<pair<char, char>> pairs;
        for (int i = 0; i + d < s.size(); i++) {
            if (pairs.count({ s[i], s[i + d] })) {
                cout << s << " is NOT surprising.\n";
                return 1;
            }
            pairs.insert({ s[i], s[i + d] });
        }
    }

    cout << s << " is surprising.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}