#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char type;
    string number;
    int h1, m1, h2, m2;
    if (!(cin >> type >> number >> h1 >> m1 >> h2 >> m2))
        return 0;

    int l = h1 * 60 + m1, r = h2 * 60 + m2;

    static vector<pair<int, int>> time = {
        { 0, 8 * 60 },
        { 8 * 60, 18 * 60 },
        { 18 * 60, 22 * 60 },
        { 22 * 60, 24 * 60 }
    };

    static vector<vector<int>> cost = {
        { 2, 10, 6, 2 },
        { 5, 25, 15, 5 },
        { 13, 53, 33, 13 },
        { 17, 87, 47, 17 },
        { 30, 144, 80, 30 }
    };

    vector<int> timeSpent(4);
    int totalCost = 0;
    for (int i = 0; i < 4; i++) {
        auto &[tl, tr] = time[i];
        if (l < r) {
            timeSpent[i] = max(0, min(r, tr) - max(l, tl));
        } else {
            timeSpent[i] = max(0, min(24 * 60, tr) - max(l, tl));
            timeSpent[i] += max(0, min(r, tr) - max(0, tl));
        }
        totalCost += timeSpent[i] * cost[type - 'A'][i];
    }

    cout << setw(10) << number;
    cout << setw(6) << timeSpent[1];
    cout << setw(6) << timeSpent[2];
    cout << setw(6) << timeSpent[0] + timeSpent[3];
    cout << setw(3) << type;
    cout << setw(8) << setprecision(2) << fixed << totalCost / 100.0 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}