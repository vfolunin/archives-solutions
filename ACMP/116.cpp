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

    vector<int> p(w);
    int res = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            p[x] = (a[y][x] == '1' ? p[x] + 1 : 0);

        vector<int> l(w, -1), stack;
        for (int x = w - 1; x >= 0; x--) {
            while (!stack.empty() && p[stack.back()] > p[x]) {
                l[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }

        vector<int> r(w, w);
        stack.clear();
        for (int x = 0; x < w; x++) {
            while (!stack.empty() && p[stack.back()] > p[x]) {
                r[stack.back()] = x;
                stack.pop_back();
            }
            stack.push_back(x);
        }

        for (int x = 0; x < w; x++)
            res = max(res, p[x] * (r[x] - l[x] - 1));
    }

    cout << res;
}