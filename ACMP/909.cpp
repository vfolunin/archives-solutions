#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int startY, int startX) {
    queue<pair<int, int>> q;

    int sCount = 1;
    int xCount = a[startY][startX] == 'X';
    a[startY][startX] = '-';
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '-') {
                sCount++;
                xCount += a[ty][tx] == 'X';
                a[ty][tx] = '-';
                q.push({ ty, tx });
            }
        }
    }

    if (xCount == 0)
        return 0;
    else if (xCount < sCount)
        return 1;
    else
        return 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;
    
    vector<int> res(3);
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] != '-')
                res[bfs(a, y, x)]++;

    for (int value : res)
        cout << value << " ";
}