#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    string ops;
    cin >> size >> ops;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            a[y][x] = y * size + x + 1;

    a[size - 1][size - 1] = 0;
    int y = size - 1, x = size - 1;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    string dc = "URDL";

    for (int i = 0; i < ops.size(); i++) {
        int d = dc.find(ops[i]);
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (ty < 0 || ty >= size || tx < 0 || tx >= size) {
            cout << "ERROR " << i + 1;
            return 0;
        }

        swap(a[y][x], a[ty][tx]);
        y = ty;
        x = tx;
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}