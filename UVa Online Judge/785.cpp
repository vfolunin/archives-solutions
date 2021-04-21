#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void floodFill(vector<string> &a, int y, int x, char c) {
    queue<int> q;
    q.push(y);
    q.push(x);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx] == ' ') {
                a[ty][tx] = c;
                q.push(ty);
                q.push(tx);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a;
    while (1) {
        string line;
        if (!getline(cin, line))
            break;
        a.push_back(line);
    }

    for (int top = 0, bottom = 0; top < a.size(); bottom++, top = bottom) {
        while (a[bottom][0] != '_')
            bottom++;

        char contour = ' ';
        for (int y = top; contour == ' ' && y < bottom; y++)
            for (int x = 0; contour == ' ' && x < a[y].size(); x++)
                if (a[y][x] != ' ' && a[y][x] != '_')
                    contour = a[y][x];

        for (int y = top; y < bottom; y++)
            for (int x = 0; x < a[y].size(); x++)
                if (a[y][x] != ' ' && a[y][x] != '_' && a[y][x] != contour)
                    floodFill(a, y, x, a[y][x]);
    }

    for (string &line : a)
        cout << line << "\n";
}