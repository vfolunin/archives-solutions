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

    int h, w;
    cin >> h >> w;
    cin.ignore();

    vector<string> a(h);
    for (string &row : a)
        getline(cin, row);

    vector<int> dy = { 1, 0, -1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    vector<vector<int>> seen(h, vector<int>(w));
    int y = 1, x = 1, curD = 0, res = 0;

    for (int i = 0; i < 2e7; i++) {
        if (y == h - 2 && x == w - 2) {
            cout << res;
            return 0;
        }

        seen[y][x]++;
        res++;

        int bestD = -1, bestSeen = 1e9, curSeen = 1e9;
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (a[ty][tx] == '@')
                continue;

            if (bestSeen > seen[ty][tx]) {
                bestSeen = seen[ty][tx];
                bestD = d;
            }

            if (d == curD)
                curSeen = seen[ty][tx];
        }

        if (bestD == -1)
            break;

        if (curSeen > bestSeen)
            curD = bestD;

        y += dy[curD];
        x += dx[curD];
    }

    cout << -1;
}