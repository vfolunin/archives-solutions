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
    for (string &s : a)
        cin >> s;

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            res += y + 1 < h && a[y][x] == '.' && a[y + 1][x] == '.';
            res += x + 1 < w && a[y][x] == '.' && a[y][x + 1] == '.';
        }
    }

    cout << res;
}