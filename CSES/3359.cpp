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
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<pair<int, int>> cells = { { 0, 0 } };
    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    visited[0][0] = 1;

    string res;

    while (1) {
        res += a[cells[0].first][cells[0].second];

        vector<pair<int, int>> nextCells;
        
        for (auto &[y, x] : cells) {
            for (auto &[ty, tx] : vector<pair<int, int>>{ { y + 1, x }, { y, x + 1 } }) {
                if (ty < a.size() && tx < a[0].size() && !visited[ty][tx]) {
                    visited[ty][tx] = 1;
                    if (nextCells.empty() || a[nextCells[0].first][nextCells[0].second] == a[ty][tx])
                        nextCells.push_back({ ty, tx });
                    else if (a[nextCells[0].first][nextCells[0].second] > a[ty][tx])
                        nextCells = { { ty, tx } };
                }
            }
        }

        if (nextCells.empty())
            break;

        cells.swap(nextCells);
    }

    cout << res;
}
