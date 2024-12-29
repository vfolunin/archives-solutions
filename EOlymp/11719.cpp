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

    int size, factor;
    cin >> size >> factor;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<int>> res(size, vector<int>(size));
    for (int size = 2; size <= p.size(); size++) {
        for (int l = 0, r = size - 1; r < p.size(); l++, r++) {
            res[l][r] = 1e9;
            for (int m = l; m < r; m++)
                res[l][r] = min(res[l][r], res[l][m] + res[m + 1][r] + factor * getSum(p, l, r));
        }
    }

    cout << res[0][p.size() - 1];
}