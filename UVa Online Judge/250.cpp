#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double sum(vector<vector<double>> &p, int y1, int x1, int y2, int x2) {
    if (y1 > y2 || x1 > x2)
        return 0;
    double res = p[y2][x2];
    if (y1)
        res -= p[y1 - 1][x2];
    if (x1)
        res -= p[y2][x1 - 1];
    if (y1 && x1)
        res += p[y1 - 1][x1 - 1];
    return res;
}

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<vector<double>> p(h, vector<double>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> p[y][x];
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    int cy, cx;
    double cd = 1e9;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            double dy = abs(sum(p, 0, 0, y - 1, w - 1) - sum(p, y + 1, 0, h - 1, w - 1));
            double dx = abs(sum(p, 0, 0, h - 1, x - 1) - sum(p, 0, x + 1, h - 1, w - 1));
            if (cd + 1e-9 >= dy + dx) {
                cy = y;
                cx = x;
                cd = dy + dx;
            }
        }
    }

    cout << "Case " << test << ": center at (" << cy + 1 << ", " << cx + 1 << ")\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}