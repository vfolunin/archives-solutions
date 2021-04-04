#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<string> a(3);
    int k[2] = {};
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        for (int j = 0; j < 3; j++)
            if (a[i][j] != '.')
                k[a[i][j] == 'X']++;
    }

    if (k[0] > k[1] || k[0] + 1 < k[1]) {
        cout << "no\n";
        return;
    }

    bool win[2] = {};
    for (int i = 0; i < 3; i++) {
        if (a[i][0] != '.')
            win[a[i][0] == 'X'] |= a[i][0] == a[i][1] && a[i][0] == a[i][2];
        if (a[0][i] != '.')
            win[a[0][i] == 'X'] |= a[0][i] == a[1][i] && a[0][i] == a[2][i];
    }
    if (a[0][0] != '.')
        win[a[0][0] == 'X'] |= a[0][0] == a[1][1] && a[0][0] == a[2][2];
    if (a[0][2] != '.')
        win[a[0][2] == 'X'] |= a[0][2] == a[1][1] && a[0][2] == a[2][0];

    cout << (win[0] && win[1] || win[0] && k[0] < k[1] || win[1] && k[0] == k[1] ? "no\n" : "yes\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}