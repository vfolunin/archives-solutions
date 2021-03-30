#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w, t;
    cin >> h >> w >> t;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    for (int i = 0; i < t; i++) {
        vector<string> b = a;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                static int dy[] = { -1, 0, 1, 0 };
                static int dx[] = { 0, 1, 0, -1 };
                static string signs = "RSP";

                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w &&
                        a[ty][tx] == signs[(signs.find(a[y][x]) + 2) % 3])
                        b[y][x] = a[ty][tx];
                }
            }
        }
        a = b;
    }

    if (test)
        cout << "\n";
    for (string &row : a)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}