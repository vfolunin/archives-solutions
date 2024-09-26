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

    vector<vector<int>> cost(s.size() + 1, vector<int>(2));
    cost[0][1] = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            cost[i + 1][0] = min(cost[i][0] + 1, cost[i][1] + 1);
            cost[i + 1][1] = min(cost[i][0] + 1, cost[i][1]);
        } else if (s[i] == 'S') {
            cost[i + 1][0] = min(cost[i][0], cost[i][1] + 1);
            cost[i + 1][1] = min(cost[i][0] + 1, cost[i][1] + 1);
        } else {
            cost[i + 1][0] = min(cost[i][0] + 1, cost[i][1] + 2);
            cost[i + 1][1] = min(cost[i][0] + 2, cost[i][1] + 1);
        }
    }

    cout << cost.back()[0];
}