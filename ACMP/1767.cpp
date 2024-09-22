#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> read(int size) {
    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> res;
    for (int ring = 0, ringSize = size - 1; ring < size; ring++, ringSize -= 2) {
        vector<int> row;
        for (int i = 0; i < ringSize; i++)
            row.push_back(a[ring][ring + i]);
        for (int i = 0; i < ringSize; i++)
            row.push_back(a[ring + i][size - 1 - ring]);
        for (int i = 0; i < ringSize; i++)
            row.push_back(a[size - 1 - ring][size - 1 - ring - i]);
        for (int i = 0; i < ringSize; i++)
            row.push_back(a[size - 1 - ring - i][ring]);

        res.push_back(row);
        for (int i = 0; i < row.size(); i++) {
            rotate(row.begin(), row.begin() + 1, row.end());
            res.back() = min(res.back(), row);
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a = read(size);
    vector<vector<int>> b = read(size);

    cout << (a == b ? "YES" : "NO");
}