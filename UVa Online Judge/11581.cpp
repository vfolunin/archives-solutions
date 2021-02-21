#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    int mask = 0;
    for (int i = 8; i >= 0; i--) {
        char c;
        cin >> c;
        mask |= (c - '0') << i;
    }
    return mask;
}

int next(int mask) {
    int nextMask = 0;
    int di[] = { -1, 0, 1, 0 };
    int dj[] = { 0, 1, 0, -1 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int s = 0;
            for (int d = 0; d < 4; d++) {
                int ti = i + di[d], tj = j + dj[d];
                if (0 <= ti && ti < 3 && 0 <= tj && tj < 3 && (mask & (1 << (ti * 3 + tj))))
                    s ^= 1;
            }
            nextMask |= s << (i * 3 + j);
        }
    }
    return nextMask;
}

int k(int mask1, int mask2) {
    static vector<vector<int>> memo(512, vector<int>(512, -1));
    if (memo[mask1][mask2] != -1)
        return memo[mask1][mask2];

    int &res = memo[mask1][mask2];
    map<int, int> seen;

    for (int i = 0; 1; i++) {
        if (seen.count(mask1)) {
            if (!seen.count(mask2))
                return res = 0;
            if (seen[mask2] >= seen[mask1])
                return res = 2;
            return res = 1;
        }

        seen[mask1] = i;
        mask1 = next(mask1);
    }
}

void solve() {
    int mask1 = read(), mask2 = mask1;

    int i = 0;
    while (k(mask1, mask2) != 2) {
        i++;
        mask2 = next(mask2);
    }

    cout << i - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}