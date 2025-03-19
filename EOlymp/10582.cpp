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

    int size, maxCoord;
    cin >> size >> maxCoord;

    vector<pair<int, int>> cells(size);
    for (auto &[x, y] : cells)
        cin >> x >> y;

    int res = size;
    for (auto &[borderX, _] : cells) {
        for (auto &[_, borderY] : cells) {
            vector<int> count(4);
            for (auto &[x, y] : cells)
                count[(x < borderX) * 2 + (y < borderY)]++;
            res = min(res, *max_element(count.begin(), count.end()));
        }
    }

    cout << res;
}