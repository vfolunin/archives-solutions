#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, y = 0, x;
    cin >> h >> w >> x;

    if (!h && !w)
        return 0;

    x--;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    map<char, int> dy = { {'N', -1}, {'S', 1} };
    map<char, int> dx = { {'W', -1}, {'E', 1} };
    vector<vector<int>> seen(h, vector<int>(w));

    for (int i = 1; 1; i++) {
        seen[y][x] = i;

        int ty = y + dy[a[y][x]];
        int tx = x + dx[a[y][x]];

        if (ty < 0 || ty >= h || tx < 0 || tx >= w) {
            cout << i << " step(s) to exit\n";
            return 1;
        }

        if (seen[ty][tx]) {
            cout << seen[ty][tx] - 1 << " step(s) ";
            cout << "before a loop of " << i - seen[ty][tx] + 1 << " step(s)\n";
            return 1;
        }

        y = ty;
        x = tx;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}