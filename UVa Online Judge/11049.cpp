#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool between(int a, int x, int b) {
    return a <= x && x <= b || a >= x && x >= b;
}

struct Wall {
    int y1, x1, y2, x2;

    bool blocks(int y, int x, int ty, int tx) {
        if (y1 == y2)
            return (y == y1 - 1 && ty == y1 || y == y1 && ty == y1 - 1) && between(x1, x, x2 - 1);
        else
            return (x == x1 - 1 && tx == x1 || x == x1 && tx == x1 - 1) && between(y1, y, y2 - 1);
    }
};

string bfs(vector<Wall> &walls, int startY, int startX, int finishY, int finishX) {
    queue<int> q;
    vector<vector<int>> pred(6, vector<int>(6, -1));

    q.push(startY);
    q.push(startX);
    pred[startY][startX] = -2;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    static string dc = "NESW";

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < 6 && 0 <= tx && tx < 6 && 
                !walls[0].blocks(y, x, ty, tx) && !walls[1].blocks(y, x, ty, tx) && !walls[2].blocks(y, x, ty, tx)) {
                if (pred[ty][tx] == -1) {
                    q.push(ty);
                    q.push(tx);
                    pred[ty][tx] = d;
                }
            }
        }
    }

    string res;
    for (int y = finishY, x = finishX; y != startY || x != startX; ) {
        int d = pred[y][x];
        res += dc[d];
        int py = y - dy[d];
        int px = x - dx[d];
        y = py;
        x = px;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool solve() {
    int startY, startX, finishY, finishX;
    if (!(cin >> startX >> startY >> finishX >> finishY))
        return 0;
    startY--;
    startX--;
    finishY--;
    finishX--;

    vector<Wall> walls(3);
    for (auto &[y1, x1, y2, x2] : walls)
        cin >> x1 >> y1 >> x2 >> y2;
    
    string res = bfs(walls, startY, startX, finishY, finishX);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}