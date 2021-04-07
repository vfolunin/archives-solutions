#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n, h, w, roundCount;
    cin >> n >> h >> w >> roundCount;

    if (!n)
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    for (int i = 0; i < roundCount; i++) {
        vector<vector<int>> b = a;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                static int dy[] = { -1, 0, 1, 0 };
                static int dx[] = { 0, 1, 0, -1 };

                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && (a[ty][tx] + 1) % n == a[y][x])
                        b[y][x] = a[ty][tx];
                }
            }
        }
        a = b;
    }

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cout << a[y][x] << (x + 1 < w ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}