#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, size;
    cin >> width >> size;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;
    p.push_back(width);

    vector<vector<int>> cost(p.size(), vector<int>(p.size()));
    for (int len = 2; len <= p.size(); len++) {
        for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
            cost[l][r] = 1e9;
            for (int m = l; m < r; m++)
                cost[l][r] = min(cost[l][r], cost[l][m] + cost[m + 1][r] + getSum(p, l, r));
        }
    }

    cout << cost[0][size];
}