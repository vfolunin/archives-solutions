#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int value, int targetLen, int targetMod) {
    int len = 0, sum = 0;
    for ( ; value; value /= 10) {
        len++;
        sum += value % 10;
    }
    return len == targetLen && sum % targetMod == 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int targetLen, targetMod;
    cin >> targetLen >> targetMod;

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += isGood(a[y][x], targetLen, targetMod);

    cout << res;
}