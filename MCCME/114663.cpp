#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    unordered_map<int, vector<int>> ys, xs;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            ys[value].push_back(y);
            xs[value].push_back(x);
        }
    }

    long long res = 0;
    for (const unordered_map<int, vector<int>> &coords : { ys, xs }) {
        for (auto [value, coords] : coords) {
            sort(coords.begin(), coords.end());

            long long lSum = 0, lSize = 0;
            for (int coord : coords) {
                res += coord * lSize - lSum;
                lSum += coord;
                lSize++;
            }
        }
    }

    cout << res;
}