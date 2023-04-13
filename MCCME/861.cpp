#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int countLess(vector<int> &a, vector<int> &b, int value) {
    return (lower_bound(a.begin(), a.end(), value) - a.begin()) + (lower_bound(b.begin(), b.end(), value) - b.begin());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        int d, p, q, mod;
        cin >> a[y][0] >> d >> p >> q >> mod;
        for (int x = 1; x < w; x++) {
            a[y][x] = a[y][x - 1] + d;
            d = (p * d + q) % mod;
        }
        sort(a[y].begin(), a[y].end());
    }

    for (int y1 = 0; y1 < h; y1++) {
        for (int y2 = y1 + 1; y2 < h; y2++) {
            int l = -1.01e9, r = 1.01e9;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (countLess(a[y1], a[y2], m) < w)
                    l = m;
                else
                    r = m;
            }
            cout << l << "\n";
        }
    }
}