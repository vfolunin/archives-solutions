#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<char, int> price;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> price[c];
    }

    int m;
    cin >> m;

    int res = 0;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);
        for (char c : line)
            if (price.count(c))
                res += price[c];
    }

    cout.precision(2);
    cout << fixed << res / 100.0 << "$\n";
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