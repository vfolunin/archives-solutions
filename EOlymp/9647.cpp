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

    int size;
    cin >> size;

    vector<pair<int, int>> a(size);
    for (auto &[h, w] : a)
        cin >> h >> w;

    vector<vector<long long>> minOps(size, vector<long long>(size));

    for (int length = 2; length <= size; length++) {
        for (int l = 0, r = l + length - 1; r < size; l++, r++) {
            minOps[l][r] = 1e18;
            for (int m = l; m < r; m++)
                minOps[l][r] = min(minOps[l][r], minOps[l][m] + minOps[m + 1][r] + 1LL * a[l].first * a[m].second * a[r].second);
        }
    }

    cout << minOps[0][size - 1];
}