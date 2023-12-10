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

    int h, w;
    cin >> h >> w;

    int res = 1e9;

    for (int y = 0; y < h; y++) {
        int maxValue = -1e9;

        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            maxValue = max(maxValue, value);
        }

        res = min(res, maxValue);
    }

    cout << res;
}