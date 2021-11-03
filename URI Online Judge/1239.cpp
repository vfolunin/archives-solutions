#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    bool b = 0, i = 0;

    for (char c : line) {
        if (c == '*') {
            cout << (b ? "</b>" : "<b>");
            b ^= 1;
        } else if (c == '_') {
            cout << (i ? "</i>" : "<i>");
            i ^= 1;
        } else {
            cout << c;
        }
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}