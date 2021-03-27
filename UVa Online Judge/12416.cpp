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

    int curRow = 0, maxRow = 0;
    for (char c : line) {
        if (c == ' ')
            curRow++;
        else
            curRow = 0;
        maxRow = max(maxRow, curRow);
    }

    int res = 0;
    while (maxRow > 1) {
        res++;
        maxRow = maxRow / 2 + maxRow % 2;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}