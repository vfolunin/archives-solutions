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
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x])
                a[y][x] = 0;
            else
                a[y][x] = 1 + (y ? a[y - 1][x] : 0);
        }
    }

    int res = 0;

    for (int y = 0; y < h; y++) {
        vector<int> l(w, -1), stack;
        for (int x = w - 1; x >= 0; x--) {
            while (!stack.empty() && a[y][stack.back()] > a[y][x]) {
                l[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }

        vector<int> r(w, w);
        stack.clear();
        for (int x = 0; x < w; x++) {
            while (!stack.empty() && a[y][stack.back()] > a[y][x]) {
                r[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }

        for (int x = 0; x < w; x++)
            res = max(res, a[y][x] * (r[x] - l[x] - 1));
    }

    cout << res;
}