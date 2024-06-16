#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    cin >> test;

    vector<int> a(15);
    for (int &value : a)
        cin >> value;

    int res = -1;
    for (int l = 0; l < a.size(); l++) {
        int minValue = a[l];
        for (int r = l; r < a.size(); r++) {
            minValue = min(minValue, a[r]);
            res += (!l || a[l - 1] < minValue) && (r + 1 == a.size() || a[r + 1] < minValue);
        }
    }

    cout << test << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}