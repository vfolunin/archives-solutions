#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> visited(h, vector<int>(w));

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    int y = h - 1, x = 0, d = 1;
    while (1) {
        int ty = y + dy[(d + 1) % 4];
        int tx = x + dx[(d + 1) % 4];
        if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == '0')
            d = (d + 1) % 4;

        while (1) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == '0') {
                y = ty;
                x = tx;
                break;
            } else {
                d = (d + 3) % 4;
            }
        }

        visited[y][x]++;
        if (y == h - 1 && x == 0)
            break;
    }

    vector<int> countVisited(5);
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == '0')
                countVisited[visited[y][x]]++;

    for (int c : countVisited)
        cout << setw(3) << c;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}