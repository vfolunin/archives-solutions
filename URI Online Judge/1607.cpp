#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= b[i])
            res += b[i] - a[i];
        else
            res += 'z' - a[i] + b[i] - 'a' + 1;
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