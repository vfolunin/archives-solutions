#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n)));
    int z = n - 1, y = n / 2, x = n / 2;

    for (int i = 1; i <= n * n * n; i++) {
        a[z][y][x] = i;

        if (!a[(z + 1) % n][y][(x + 1) % n]) {
            z = (z + 1) % n;
            x = (x + 1) % n;
        } else if (!a[(z + 1) % n][(y + n - 1) % n][x]) {
            z = (z + 1) % n;
            y = (y + n - 1) % n;
        } else {
            z = (z + n - 1) % n;
        }
    }

    if (test)
        cout << "\n";

    for (int z = 0; z < n; z++) {
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                cout << setw(5) << a[z][y][x] << (x + 1 < n ? " " : "\n");
        cout << (z + 1 < n ? "\n" : "");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}