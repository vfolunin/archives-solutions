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

    vector<string> b(h);
    for (string &row : b)
        cin >> row;

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += a[y][x] == b[y][x];

    cout << res;
}