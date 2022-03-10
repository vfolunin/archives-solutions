#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int level;
    if (!(cin >> level))
        return 0;

    string line;
    cin.ignore();
    getline(cin, line);

    string backslashes((1 << level) - 1, '\\');

    for (char c : line) {
        if ('!' <= c && c <= '*' || '[' <= c && c <= ']')
            cout << backslashes;
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