#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> w >> h))
        return 0;

    vector<map<int, int>> m(h);

    for (int x = 0; x < w; x++) {
        int k;
        cin >> k;
        vector<int> ys(k), vals(k);
        for (int &y : ys) {
            cin >> y;
            y--;
        }
        for (int &vals : vals)
            cin >> vals;
        for (int i = 0; i < k; i++)
            m[ys[i]][x] = vals[i];
    }

    cout << h << " " << w << "\n";
    for (int y = 0; y < h; y++) {
        cout << m[y].size();
        for (auto it = m[y].begin(); it != m[y].end(); it++)
            cout << " " << it->first + 1;
        cout << "\n";
        for (auto it = m[y].begin(); it != m[y].end(); it++)
            cout << it->second << (next(it) != m[y].end() ? " " : "");
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}