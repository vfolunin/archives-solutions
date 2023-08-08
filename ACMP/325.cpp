#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(int y, int x, int finishY, int finishX, int depth) {
    if (depth > 2)
        return -1;

    if (depth && y == finishY && x == finishX)
        return depth;

    static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (ty < 0 || ty >= 8 || tx < 0 || tx >= 8)
            continue;

        int res = dfs(ty, tx, finishY, finishX, depth + 1);
        if (res != -1)
            return res;
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char startX, startY, comma, finishX, finishY;
    cin >> startX >> startY >> comma >> finishX >> finishY;

    int dist = dfs(startY - '1', startX - 'a', finishY - '1', finishX - 'a', 0);

    if (dist != -1)
        cout << dist;
    else
        cout << "NO";
}