#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x) {
    a[y][x] = '.';

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '*')
            dfs(a, ty, tx);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int res = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '*') {
                res++;
                dfs(a, y, x);
            }
        }
    }

    cout << res;
}