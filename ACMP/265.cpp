#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfsPerimeter(vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;
    int res = 0;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || visited[ty][tx])
            continue;

        if (a[ty][tx] != 'x')
            res++;
        else
            res += dfsPerimeter(a, ty, tx, visited);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cellCount;
    cin >> cellCount;

    vector<string> a(10, string(10, ' '));
    int y, x;

    for (int i = 0; i < cellCount; i++) {
        cin >> y >> x;
        a[y][x] = 'x';
    }

    vector<vector<int>> visited(10, vector<int>(10));
    cout << dfsPerimeter(a, y, x, visited);
}