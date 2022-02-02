#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int typeCount, target;
    cin >> typeCount >> target;

    vector<vector<int>> minItems(target + 1, vector<int>(target + 1, 1e9));
    minItems[0][0] = 0;

    for (int i = 0; i < typeCount; i++) {
        int x, y;
        cin >> x >> y;

        for (int sx = x; sx <= target; sx++)
            for (int sy = y; sy <= target; sy++)
                minItems[sx][sy] = min(minItems[sx][sy], minItems[sx - x][sy - y] + 1);
    }

    int res = 1e9;
    for (int sx = 0; sx <= target; sx++)
        for (int sy = 0; sy <= target; sy++)
            if (sx * sx + sy * sy == target * target)
                res = min(res, minItems[sx][sy]);

    if (res != 1e9)
        cout << res << "\n";
    else
        cout << "not possible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}