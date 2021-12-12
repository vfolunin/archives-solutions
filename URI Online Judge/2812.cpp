#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> odd;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2)
            odd.push_back(x);
    }
    sort(odd.begin(), odd.end());

    vector<int> res;
    for (int l = 0, r = (int)odd.size() - 1; l <= r; l++, r--) {
        res.push_back(odd[r]);
        if (l < r)
            res.push_back(odd[l]);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "");
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}