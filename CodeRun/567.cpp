#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, int color) {
    a[y][x] = color;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == -1)
            dfs(a, ty, tx, color);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a(1);
    for (int value; cin >> value; ) {
        a.back().push_back(-value);
        if (cin.peek() == '\n')
            a.emplace_back();
    }
    a.pop_back();

    int componentCount = 0;
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            if (a[y][x] == -1)
                dfs(a, y, x, ++componentCount);

    cout << componentCount << "\n";
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}