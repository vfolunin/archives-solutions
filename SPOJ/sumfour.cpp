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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(4, vector<int>(n));
    for (int j = 0; j < n; j++)
        for (int i = 0; i < 4; i++)
            cin >> a[i][j];

    vector<int> sums;
    for (int x : a[0])
        for (int y : a[1])
            sums.push_back(x + y);
    sort(sums.begin(), sums.end());

    long long res = 0;
    for (int x : a[2]) {
        for (int y : a[3]) {
            auto [l, r] = equal_range(sums.begin(), sums.end(), -x - y);
            res += r - l;
        }
    }

    cout << res;
}