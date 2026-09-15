#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int i, int j, vector<int> &cost) {
    static vector<vector<int>> memo(1001, vector<int>(1001, -1));
    int &res = memo[i][j];
    if (res != -1)
        return res;

    if (i == cost.size() - 1)
        return res = 0;

    res = 1e9;
    if (i >= j)
        res = min(res, rec(i - j, j, cost) + cost[i - j]);
    if (i + j + 1 < cost.size())
        res = min(res, rec(i + j + 1, j + 1, cost) + cost[i + j + 1]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> cost(size);
    for (int &c : cost)
        cin >> c;

    cout << rec(0, 0, cost);
}