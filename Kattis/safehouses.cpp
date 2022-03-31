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

    vector<pair<int, int>> spies, houses;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            char c;
            cin >> c;
            if (c == 'S')
                spies.push_back({ y, x });
            else if (c == 'H')
                houses.push_back({ y, x });
        }
    }

    int maxDist = 0;
    for (auto &[sy, sx] : spies) {
        int curDist = 1e9;
        for (auto &[hy, hx] : houses)
            curDist = min(curDist, abs(sy - hy) + abs(sx - hx));
        maxDist = max(maxDist, curDist);
    }

    cout << maxDist;
}