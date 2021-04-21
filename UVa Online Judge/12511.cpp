#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &x : b)
        cin >> x;

    vector<vector<int>> lcis(aSize, vector<int>(bSize));
    for (int i = 0; i < aSize; i++) {
        int maxPredLcis = 0;
        for (int j = 0; j < bSize; j++) {
            if (i)
                lcis[i][j] = lcis[i - 1][j];
            if (a[i] == b[j])
                lcis[i][j] = maxPredLcis + 1;
            if (b[j] < a[i])
                maxPredLcis = max(maxPredLcis, lcis[i][j]);
        }
    }

    int res = 0;
    for (int i = 0; i < aSize; i++)
        for (int j = 0; j < bSize; j++)
            res = max(res, lcis[i][j]);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}