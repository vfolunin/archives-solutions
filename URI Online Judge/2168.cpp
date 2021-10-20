#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int y = 0; y <= n; y++)
        for (int x = 0; x <= n; x++)
            cin >> a[y][x];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            cout << (a[y][x] + a[y][x + 1] + a[y + 1][x] + a[y + 1][x + 1] >= 2 ? "S" : "U");
        cout << "\n";
    }
}