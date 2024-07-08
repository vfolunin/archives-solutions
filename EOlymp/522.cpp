#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pressCount, elevatorCount;
    if (!(cin >> pressCount >> elevatorCount))
        return 0;

    int res = 1e9;
    for (int i = 0; i < elevatorCount; i++) {
        int up, down;
        cin >> up >> down;

        int upCount = (down * pressCount + up + down) / (up + down);
        if (0 <= upCount && upCount <= pressCount)
            res = min(res, up * upCount - down * (pressCount - upCount));
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}