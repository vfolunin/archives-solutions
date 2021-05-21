#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int snowWeight, treeCount;
    cin >> snowWeight >> treeCount;

    vector<int> tree(treeCount);
    for (int &t : tree) {
        cin >> t;
        t -= snowWeight;
    }

    int res = 0;
    for (int l = 0, r = 0, t = 0; r < treeCount; l++) {
        while (r < treeCount && t + (tree[r] >= 0) <= 5) {
            t += tree[r] >= 0;
            r++;
        }
        res = max(res, r - l);
        t -= tree[l] >= 0;
    }

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