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

    const long long MOD = 998244353;
    vector<vector<long long>> ways(w, vector<long long>(h));
    for (int y = 0; y < h; y++)
        ways[0][y] = 1;

    for (int x = 1; x < w; x++)
        for (int y = 0; y < h; y++)
            for (int py = 0; py < h; py++)
                if (py != y)
                    ways[x][y] = (ways[x][y] + ways[x - 1][py]) % MOD;

    long long res = 0;
    for (int y = 0; y < h; y++)
        res = (res + ways.back()[y]) % MOD;

    cout << res;
}