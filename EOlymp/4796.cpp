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

    vector<int> xs(size), ys(size);
    for (int i = 0; i < size; i++)
        cin >> xs[i] >> ys[i];

    vector<int> sortedXs = xs;
    vector<int> sortedYs = ys;
    nth_element(sortedXs.begin(), sortedXs.begin() + size / 2, sortedXs.end());
    nth_element(sortedYs.begin(), sortedYs.begin() + size / 2, sortedYs.end());
    int cx = sortedXs[size / 2], cy = sortedYs[size / 2];

    int resX = 0, resY = 0, resDist = 1e9;
    for (int x = cx - 6; x < cx + 6; x++) {
        for (int y = cy - 6; y < cy + 6; y++) {
            int dist = 0, skip = 0;
            for (int i = 0; i < size; i++) {
                if (xs[i] == x && ys[i] == y) {
                    skip = 1;
                    break;
                }
                dist += abs(x - xs[i]) + abs(y - ys[i]);
            }

            if (!skip && resDist > dist) {
                resDist = dist;
                resX = x;
                resY = y;
            }
        }
    }

    cout << resX << " " << resY;
}