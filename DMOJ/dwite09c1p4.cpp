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

    vector<int> count(26);
    for (char c : s)
        count[c - 'A']++;

    for (char c : s) {
        if (count[c - 'A'] == 1) {
            cout << c << "\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}