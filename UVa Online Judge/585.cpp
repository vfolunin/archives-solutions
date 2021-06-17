#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int lineCount;
    cin >> lineCount;

    if (!lineCount)
        return 0;

    cin.ignore();
    vector<string> lines(lineCount);
    for (string &line : lines)
        getline(cin, line);

    int res = 0;
    vector<vector<int>> t(lineCount);

    for (int y = 0; y < lineCount; y++) {
        t[y].resize(lines[y].size());
        for (int x = 0; x < lines[y].size(); x++) {
            if (lines[y][x] != '-') {
                t[y][x] = 0;
            } else {
                t[y][x] = 1;
                if (y && 0 <= x - 1 && x + 1 < t[y - 1].size())
                    t[y][x] += min(t[y - 1][x - 1], min(t[y - 1][x], t[y - 1][x + 1]));
            }
            if ((y + x) % 2 == 0)
                res = max(res, t[y][x]);
        }
    }

    for (int y = lineCount - 1; y >= 0; y--) {
        for (int x = 0; x < lines[y].size(); x++) {
            if (lines[y][x] != '-') {
                t[y][x] = 0;
            } else {
                t[y][x] = 1;
                if (y < lineCount - 1 && 0 <= x - 1 && x + 1 < t[y + 1].size())
                    t[y][x] += min(t[y + 1][x - 1], min(t[y + 1][x], t[y + 1][x + 1]));
            }
            if ((y + x) % 2)
                res = max(res, t[y][x]);
        }
    }

    cout << "Triangle #" << test << "\n";
    cout << "The largest triangle area is " << res * res << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
