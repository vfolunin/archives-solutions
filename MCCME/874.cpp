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

    int size, colorCount;
    cin >> size >> colorCount;

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for (int size = 2; size <= a.size(); size++) {
        for (int l = 0, r = size - 1; r < a.size(); l++, r++) {
            res[l][r] = 1e9;
            for (int m = l; m < r; m++)
                res[l][r] = min(res[l][r], res[l][m] + res[m + 1][r] + (a[m] != a[r]));
        }
    }

    cout << res[0][a.size() - 1];
}