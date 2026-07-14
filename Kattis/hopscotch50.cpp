#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, target;
    cin >> size >> target;

    vector<vector<tuple<int, int, int>>> dist(target);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            dist[value - 1].push_back({ y, x, 0 });
        }
    }

    for (int value = target - 2; value >= 0; value--) {
        for (auto &[y1, x1, dist1] : dist[value]) {
            dist1 = 1e9;
            for (auto &[y2, x2, dist2] : dist[value + 1])
                dist1 = min(dist1, abs(y1 - y2) + abs(x1 - x2) + dist2);
        }
    }

    int res = 1e9;
    for (auto &[y, x, dist] : dist[0])
        res = min(res, dist);

    cout << (res < 1e9 ? res : -1);
}