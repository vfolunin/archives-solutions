#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<int>> res(p.size(), vector<int>(p.size()));
    for (int i = 0; i < p.size(); i++)
        res[i][i] = getSum(p, i, i);

    for (int len = 2; len <= p.size(); len++)
        for (int l = 0, r = len - 1; r < p.size(); l++, r++)
            res[l][r] = getSum(p, l, r) - min(res[l + 1][r], res[l][r - 1]);

    cout << res[0][p.size() - 1];
}