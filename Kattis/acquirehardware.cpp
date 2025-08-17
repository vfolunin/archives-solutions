#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<vector<int>> res(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res[y][x] = (a[y][x] == 'I') + max(y ? res[y - 1][x] : 0, x ? res[y][x - 1] : 0);
    
    cout << res[h - 1][w - 1];
}