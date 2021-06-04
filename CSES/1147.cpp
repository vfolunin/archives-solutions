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

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> p(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == '.')
                p[y][x] = 1 + (y ? p[y - 1][x] : 0);
    
    int res = 0;
    for (int y = 0; y < h; y++) {
        vector<int> l(w), r(w), stack;

        for (int x = w - 1; x >= 0; x--) {
            while (!stack.empty() && p[y][stack.back()] > p[y][x]) {
                l[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }
        while (!stack.empty()) {
            l[stack.back()] = -1;
            stack.pop_back();
        }

        for (int x = 0; x < w; x++) {
            while (!stack.empty() && p[y][stack.back()] > p[y][x]) {
                r[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }
        while (!stack.empty()) {
            r[stack.back()] = w;
            stack.pop_back();
        }

        for (int x = 0; x < w; x++) 
            res = max(res, p[y][x] * (r[x] - l[x] - 1));
    }

    cout << res;
}