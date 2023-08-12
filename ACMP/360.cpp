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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<vector<short>> a(size, vector<short>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int res = -1e9;

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            for (int d1 = 0; d1 < dy.size(); d1++) {
                int ty1 = y + dy[d1];
                int tx1 = x + dx[d1];

                if (ty1 < 0 || ty1 >= a.size() || tx1 < 0 || tx1 >= a[0].size())
                    continue;

                for (int d2 = d1 + 1; d2 < dy.size(); d2++) {
                    int ty2 = y + dy[d2];
                    int tx2 = x + dx[d2];

                    if (ty2 < 0 || ty2 >= a.size() || tx2 < 0 || tx2 >= a[0].size())
                        continue;

                    res = max(res, a[y][x] + a[ty1][tx1] + a[ty2][tx2]);
                }
            }
        }
    }

    cout << res;
}