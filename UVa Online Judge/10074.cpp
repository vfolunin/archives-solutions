#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<vector<int>> p(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> p[i][j];
            if (i)
                p[i][j] += p[i - 1][j];
        }
    }

    int maxArea = 0;
    for (int y1 = 0; y1 < h; y1++) {
        for (int y2 = y1; y2 < h; y2++) {
            int width = 0;
            for (int x = 0; x < w; x++) {
                if (p[y2][x] - (y1 ? p[y1 - 1][x] : 0) == 0)
                    width++;
                else
                    width = 0;
                maxArea = max(maxArea, width * (y2 - y1 + 1));
            }
        }
    }

    cout << maxArea << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}