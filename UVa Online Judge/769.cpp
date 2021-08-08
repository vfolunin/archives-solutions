#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    if (test)
        cout << "\n";

    for (int step = n - 1, k = 2 * n + 1, odd = 1 - n % 2; step > 0; step--) {
        cout << k;
        for (int row = odd; row < step; row += 2)
            cout << " " << row * n + step + 1;
        for (int col = odd; col <= step; col += 2)
            cout << " " << step * n + col + 1;
        cout << "\n";

        k += 2;
        odd ^= 1;

        cout << k;
        for (int row = odd; row < step; row += 2)
            cout << " " << row * n + step + 1;
        for (int col = odd; col <= step; col += 2)
            cout << " " << step * n + col + 1;
        cout << "\n";

        k += 2;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}