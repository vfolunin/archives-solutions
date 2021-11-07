#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int bestSum(vector<int> &cost) {
    vector<int> res(cost.size());
    res[0] = cost[0];
    if (cost.size() > 1)
        res[1] = max(cost[0], cost[1]);
    for (int i = 2; i < cost.size(); i++)
        res[i] = max(res[i - 1], res[i - 2] + cost[i]);
    return res.back();
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<int> col(h);
    for (int i = 0; i < h; i++) {
        vector<int> row(w);
        for (int &x : row)
            cin >> x;
        col[i] = bestSum(row);
    }

    cout << bestSum(col) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}