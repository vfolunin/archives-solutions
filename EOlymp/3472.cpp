#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a) {
        for (int &x : row)
            cin >> x;
        reverse(row.begin(), row.end());
    }

    vector<vector<int>> weight(h, vector<int>(w, 1e9));
    vector<vector<int>> prevRow(h, vector<int>(w));

    for (int row = 0; row < h; row++)
        weight[row][0] = a[row][0];

    for (int col = 1; col < w; col++) {
        for (int row = 0; row < h; row++) {
            for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
                int pRow = (row + deltaRow + h) % h;
                if (weight[row][col] > weight[pRow][col - 1] + a[row][col] ||
                    weight[row][col] == weight[pRow][col - 1] + a[row][col] && pRow < prevRow[row][col]) {
                    weight[row][col] = weight[pRow][col - 1] + a[row][col];
                    prevRow[row][col] = pRow;
                }
            }
        }
    }

    int bestRow = 0;
    for (int row = 1; row < h; row++)
        if (weight[row][w - 1] < weight[bestRow][w - 1])
            bestRow = row;

    vector<int> path;
    for (int row = bestRow, col = w - 1; col >= 0; row = prevRow[row][col], col--)
        path.push_back(row);

    for (int i = 0; i < path.size(); i++)
        cout << path[i] + 1 << (i + 1 < path.size() ? ' ' : '\n');
    cout << weight[bestRow][w - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}