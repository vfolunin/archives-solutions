#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<string> a(size, string(size, '.'));
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int y = 0, x = 0, d = 1; 1; ) {
        a[y][x] = '*';
        bool hasNext = 0;

        for (int i = 0; i < dy.size() && !hasNext; i++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            int ty2 = ty + dy[d];
            int tx2 = tx + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && a[ty][tx] == '.' &&
                (ty2 < 0 || ty2 >= a.size() || tx2 < 0 || tx2 >= a.size() || a[ty2][tx2] == '.')) {
                y = ty;
                x = tx;
                hasNext = 1;
            } else {
                d = (d + 1) % dy.size();
            }
        }

        if (!hasNext)
            break;
    }

    if (a.size() % 2 == 0)
        a[a.size() / 2][a.size() / 2 - 1] = '.';

    for (string &s : a)
        cout << s << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}