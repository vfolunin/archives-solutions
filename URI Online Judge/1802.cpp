#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &cost, int i, int sum, vector<int> &sets) {
    if (i == cost.size()) {
        sets.push_back(sum);
        return;
    }
    for (int j = 0; j < cost[i].size(); j++)
        rec(cost, i + 1, sum + cost[i][j], sets);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> cost(5);
    for (int i = 0; i < cost.size(); i++) {
        int n;
        cin >> n;
        cost[i].resize(n);
        for (int &x : cost[i])
            cin >> x;
    }

    vector<int> sets;
    rec(cost, 0, 0, sets);
    sort(sets.rbegin(), sets.rend());

    int setCount;
    cin >> setCount;

    int res = 0;
    for (int i = 0; i < setCount; i++)
        res += sets[i];

    cout << res << "\n";
}