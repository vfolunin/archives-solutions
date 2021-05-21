#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> pFreq(size);
    for (int i = 0; i < size; i++) {
        cin >> pFreq[i];
        if (i)
            pFreq[i] += pFreq[i - 1];
    }

    vector<vector<int>> res(size, vector<int>(size));

    for (int len = 2; len <= size; len++) {
        for (int l = 0, r = len - 1; r < size; l++, r++) {
            res[l][r] = 1e9;
            for (int m = l; m <= r; m++) {
                int candidate = sum(pFreq, l, r) - sum(pFreq, m, m);
                if (l < m)
                    candidate += res[l][m - 1];
                if (m < r)
                    candidate += res[m + 1][r];
                res[l][r] = min(res[l][r], candidate);
            }
        }
    }

    cout << res[0][size - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}