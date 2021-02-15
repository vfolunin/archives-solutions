#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, mod;
    cin >> n >> mod;

    vector<vector<int>> can(2, vector<int>(mod));
    can[0][0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        fill(can[1].begin(), can[1].end(), 0);
        for (int j = 0; j < mod; j++) {
            if (can[0][j]) {
                can[1][((j + x) % mod + mod) % mod] = 1;
                can[1][((j - x) % mod + mod) % mod] = 1;
            }
        }
        can[0].swap(can[1]);
    }

    cout << (can[0][0] ? "Divisible\n" : "Not divisible\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}