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

    int size;
    cin >> size;

    const int MOD = 9929;
    vector<vector<int>> ways(size, vector<int>(size));
    ways[0][0] = 1;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y)
                ways[y][x] = (ways[y][x] + ways[y - 1][x]) % MOD;
            if (x)
                ways[y][x] = (ways[y][x] + ways[y][x - 1]) % MOD;
        }
    }

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res = (res + ways[y][x] * ways[size - 1 - y][size - 1 - x]) % MOD;

    cout << res;
}