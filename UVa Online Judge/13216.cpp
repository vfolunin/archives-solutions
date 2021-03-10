#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "0") {
        cout << "1\n";
        return;
    }

    if (s == "1") {
        cout << "66\n";
        return;
    }

    int mod = 0;
    for (char c : s)
        mod = (mod * 10 + c - '0') % 5;

    static vector<int> res = { 56, 96, 36, 76, 16 };
    cout << res[(mod + 3) % 5] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}