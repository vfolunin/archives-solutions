#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &a, int y, int x, int step) {
    a[y][x] = step;

    if (step == a.size() * a.size()) {
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++)
                cout << a[y][x] << " ";
            cout << "\n";
        }
        exit(0);
    }

    static vector<int> dy = { -2, -1, 1, 2, 2, 1, -1, -2 };
    static vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };

    vector<pair<int, int>> neighbors;
    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && !a[ty][tx])
            rec(a, ty, tx, step + 1);
    }

    a[y][x] = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    rec(a, 0, 0, 1);

    cout << "Solution does not exist";
}