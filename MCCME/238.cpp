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

    int size;
    cin >> size;

    int x1 = 0, x2 = 0;
    const int MOD = 400;

    for (int i = 0; i < size; i++) {
        int v1, t1, v2, t2;
        cin >> v1 >> t1 >> v2 >> t2;

        x1 = ((x1 + v1 * t1) % MOD + MOD) % MOD;
        x2 = ((x2 + v2 * t2) % MOD + MOD) % MOD;
    }

    int res = abs(x1 - x2);
    res = min(res, MOD - res);

    cout << res;
}