#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int tryMask(int mask, vector<vector<int>> a) {
    int res = 0;

    for (int x = 0; x < a.size(); x++) {
        if (mask & (1 << x)) {
            if (!a[0][x]) {
                a[0][x] = 1;
                res++;
            }
        } else {
            if (a[0][x])
                return 1e9;
        }
    }

    for (int y = 1; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            int parity = 0;

            static int dy[] = { -2, -1, -1 };
            static int dx[] = { 0, -1, 1 };

            for (int d = 0; d < 3; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size())
                    parity ^= a[ty][tx];
            }

            if (parity) {
                if (!a[y][x]) {
                    a[y][x] = 1;
                    res++;
                }
            } else {
                if (a[y][x])
                    return 1e9;
            }
        }
    }

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            int parity = 0;

            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };

            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size())
                    parity ^= a[ty][tx];
            }

            if (parity)
                return 1e9;
        }
    }

    return res;
}

void solve(int test) {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    int res = 1e9;
    for (int mask = 0; mask < (1 << size); mask++)
        res = min(res, tryMask(mask, a));

    cout << "Case " << test << ": " << (res != 1e9 ? res : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}