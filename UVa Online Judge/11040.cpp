#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<vector<int>> a(9, vector<int>(9));
    for (int i = 0; i < 9; i += 2)
        for (int j = 0; j <= i; j += 2)
            cin >> a[i][j];

    for (int i = 2; i < 9; i += 2) {
        for (int j = 1; j < 9; j += 2) {
            a[i][j] = (a[i - 2][j - 1] - a[i][j - 1] - a[i][j + 1]) / 2;
            a[i - 1][j - 1] = a[i][j - 1] + a[i][j];
            a[i - 1][j] = a[i][j] + a[i][j + 1];
        }
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j <= i; j++)
            cout << a[i][j] << (j + 1 <= i ? ' ' : '\n');  
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}