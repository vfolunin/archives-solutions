#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<double> cost(s.size() + 1, 1e9);
    cost[0] = 0;

    for (int size = 1; size <= s.size(); size++) {
        if (s[size - 1] == '.') {
            cost[size] = cost[size - 1];
        } else {
            for (int part = 1; part <= size; part++)
                cost[size] = min(cost[size], cost[size - part] + sqrt(part));
        }
    }

    cout << fixed << cost.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}