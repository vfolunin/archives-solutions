#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void printPath(int y, int x, vector<string> &move) {
    if (y || x) {
        printPath(y - (move[y][x] == 'D'), x - (move[y][x] == 'R'), move);
        cout << move[y][x] << " ";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> res(h, vector<int>(w, -1));
    res[0][0] = a[0][0];
    vector<string> move(h, string(w, ' '));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y && res[y][x] < res[y - 1][x] + a[y][x]) {
                res[y][x] = res[y - 1][x] + a[y][x];
                move[y][x] = 'D';
            }
            if (x && res[y][x] < res[y][x - 1] + a[y][x]) {
                res[y][x] = res[y][x - 1] + a[y][x];
                move[y][x] = 'R';
            }
        }
    }

    cout << res[h - 1][w - 1] << "\n";
    printPath(h - 1, w - 1, move);
}