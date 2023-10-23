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

    vector<int> a(size + 1);
    for (int i = 0; i < size; i++)
        cin >> a[i] >> a[i + 1];

    vector<vector<int>> res(a.size(), vector<int>(a.size() + 1));
    for (int len = 3; len <= a.size(); len++) {
        for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
            res[l][r] = 1e9;
            for (int m = l + 1; m < r; m++)
                res[l][r] = min(res[l][r], res[l][m] + res[m][r] + a[l] * a[r]);
        }
    }

    cout << res[0][a.size() - 1];
}