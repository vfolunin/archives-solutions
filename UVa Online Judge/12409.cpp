#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w;
    cin >> h >> w;

    int xorSum = 0;
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            int val;
            cin >> val;

            if ((y + x) % 2)
                xorSum ^= val;
        }
    }

    cout << "Case " << test << ": " << (xorSum ? "win\n" : "lose\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}