#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<int>> cost(s.size() + 1, vector<int>(4, 1e9));
    cost[0][0] = 0;

    for (int size = 1; size <= s.size(); size++) {
        cost[size][0] = 1;
        for (int prevSize = 0; prevSize < size; prevSize++) {
            cost[size][1] = min(cost[size][1], cost[prevSize][1] + 1);
            cost[size][2] = min(cost[size][2], cost[prevSize][2] + 1);
            cost[size][3] = min(cost[size][3], cost[prevSize][3] + 1);
        }
        if (s[size - 1] == 's') {
            cost[size][1] = min(cost[size][1], cost[size - 1][0]);
            cost[size][3] = min(cost[size][3], cost[size - 1][2]);
        } else if (s[size - 1] == 'i') {
            cost[size][2] = min(cost[size][2], cost[size - 1][1]);
        }
    }

    cout << (cost.back().back() != 1e9 ? cost.back().back() : -1);
}