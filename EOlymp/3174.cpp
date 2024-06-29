#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    const int MOD = 1e6 + 3;
    vector<vector<int>> ways(1001, vector<int>(1001));
    ways[0][0] = 1;

    for (int y = 0; y < ways.size(); y++) {
        for (int x = 0; x < ways.size(); x++) {
            if (y && x)
                ways[y][x] = (ways[y][x] + ways[y - 1][x - 1]) % MOD;
            if (y)
                ways[y][x] = (ways[y][x] + ways[y - 1][x]) % MOD;
            if (x)
                ways[y][x] = (ways[y][x] + ways[y][x - 1]) % MOD;
        }
    }

    vector<int> res(ways.size());
    for (int i = 0; i < ways.size(); i++)
        res[i] = ways[i][i];
    return res;
}

void solve() {
    int size;
    cin >> size;

    static vector<int> res = prepare();

    cout << res[size - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}