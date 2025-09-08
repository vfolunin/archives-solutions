#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, diagCount;
    cin >> h >> w >> diagCount;
    h++;
    w++;

    vector<vector<int>> diag(h, vector<int>(w));
    for (int i = 0; i < diagCount; i++) {
        int y, x;
        cin >> y >> x;

        diag[y][x] = 1;
    }

    vector<vector<double>> dist(h, vector<double>(w, 1e9));
    dist[0][0] = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                dist[y][x] = min(dist[y][x], dist[y - 1][x] + 1);
            if (x)
                dist[y][x] = min(dist[y][x], dist[y][x - 1] + 1);
            if (y && x && diag[y][x])
                dist[y][x] = min(dist[y][x], dist[y - 1][x - 1] + sqrt(2.0));
        }
    }
    
    cout << (int)round(dist.back().back() * 100);
}