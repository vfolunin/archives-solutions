#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> dfs(vector<string> &a, int y, int x) {
    a[y][x] = '#';
    int count = 1;
    bool touch[2] = {};

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < 9 && 0 <= tx && tx < 9) {
            if (a[ty][tx] == 'O') {
                touch[0] = 1;
            } else if (a[ty][tx] == 'X') {
                touch[1] = 1;
            } else if (a[ty][tx] == '.') {
                auto [recCount, recTouch] = dfs(a, ty, tx);
                count += recCount;
                if (recTouch == 0)
                    touch[0] = 1;
                if (recTouch == 1)
                    touch[1] = 1;
                if (recTouch == 2)
                    touch[0] = touch[1] = 1;
            }
        }
    }

    if (touch[0] && touch[1])
        return { 0, 2 };
    if (touch[0])
        return { count, 0 };
    if (touch[1])
        return { count, 1 };
    return { count, -1 };
}

void solve() {
    vector<string> a(9);
    for (string &row : a)
        cin >> row;

    int count[2] = {};
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (a[y][x] == '.') {
                auto [recCount, recTouch] = dfs(a, y, x);
                if (recTouch != 2)
                    count[recTouch] += recCount;
            } else if (a[y][x] == 'O') {
                count[0]++;
            } else if (a[y][x] == 'X') {
                count[1]++;
            }
        }
    }

    cout << "Black " << count[1] << " White " << count[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}