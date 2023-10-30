#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x) {
    a[y][x] = '@';

    int res = 0;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] == '#')
            res++;
        else if (a[ty][tx] == '.')
            res += dfs(a, ty, tx);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int res = dfs(a, 0, 0);
    if (a[size - 1][size - 1] != '@')
        res += dfs(a, size - 1, size - 1);

    cout << (res - 4) * 9;
}