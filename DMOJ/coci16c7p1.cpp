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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        vector<int> b(w);
        for (int &value : b)
            cin >> value;

        int res = 0;
        for (int y = 0; y < h; y++) {
            int ok = 1;
            for (int x = 0; x < w && ok; x++)
                ok &= b[x] == -1 || b[x] == a[y][x];
            res += ok;
        }

        cout << res << "\n";
    }
}