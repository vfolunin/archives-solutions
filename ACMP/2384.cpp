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

    int height, width, cellCount;
    cin >> height >> width >> cellCount;

    vector<pair<int, int>> cells(cellCount);
    for (auto &[y, x] : cells) {
        cin >> y >> x;
        y--;
        x--;
    }
    sort(cells.begin(), cells.end());

    long long res = 0;
    for (int y = 0, i = 0; y < height; y++) {
        while (i < cells.size() && cells[i].first == y) {
            width = min(width, cells[i].second);
            i++;
        }
        res += width;
    }

    cout << res;
}