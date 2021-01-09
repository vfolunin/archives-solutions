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

    vector<int> xs(n);
    for (int &x : xs)
        cin >> x;

    nth_element(xs.begin(), xs.begin() + n / 2, xs.end());
    int xMid = xs[n / 2];

    int res = 0;
    for (int x : xs)
        res += abs(x - xMid);
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