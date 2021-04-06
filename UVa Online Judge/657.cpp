#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs2(vector<string> &a, int y, int x) {
    a[y][x] = '*';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == 'X')
            dfs2(a, ty, tx);
    }
}

int dfs1(vector<string> &a, int y, int x) {
    int dots = 0;

    if (a[y][x] == 'X') {
        dfs2(a, y, x);
        dots++;
    }

    a[y][x] = '.';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '.') {
            if (a[ty][tx] == 'X') {
                dfs2(a, ty, tx);
                dots++;
            }
            if (a[ty][tx] == '*')
                dots += dfs1(a, ty, tx);
        }
    }

    return dots;
}

bool solve(int test) {
    int h, w;
    cin >> w >> h;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<int> dotCounts;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] != '.')
                dotCounts.push_back(dfs1(a, y, x));
    sort(dotCounts.begin(), dotCounts.end());

    cout << "Throw " << test << "\n";
    for (int i = 0; i < dotCounts.size(); i++)
        cout << dotCounts[i] << (i + 1 < dotCounts.size() ? " " : "\n\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}