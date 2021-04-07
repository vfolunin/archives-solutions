#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w, money;
    cin >> h >> w >> money;

    vector<vector<int>> p(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> p[y][x];
            if (y)
                p[y][x] += p[y - 1][x];
        }
    }

    int bestArea = 0;
    long long bestAreaCost = 0;

    for (int y1 = 0; y1 < h; y1++) {
        for (int y2 = y1; y2 < h; y2++) {
            long long cost = 0;
            for (int l = 0, r = 0; r < w; r++) {
                cost += p[y2][r] - (y1 ? p[y1 - 1][r] : 0);
                while (cost > money) {
                    cost -= p[y2][l] - (y1 ? p[y1 - 1][l] : 0);
                    l++;
                }

                long long area = (y2 - y1 + 1) * (r - l + 1);
                if (area > bestArea || area == bestArea && cost < bestAreaCost) {
                    bestArea = area;
                    bestAreaCost = cost;
                }
            }
        }
    }

    cout << "Case #" << test << ": " << bestArea << " " << bestAreaCost << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}