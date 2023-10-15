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

    int targetSize;
    cin >> targetSize;

    const int MOD = 1e6;
    vector<vector<vector<int>>> ways(targetSize + 1, vector<vector<int>>(2, vector<int>(4)));
    ways[0][0][3] = ways[0][1][3] = 1;

    for (int size = 1; size <= targetSize; size++) {
        for (int type = 0; type <= 1; type++) {
            if (size >= 10)
                for (int last = 1; last <= 3; last++)
                    ways[size][type][1] = (ways[size][type][1] + ways[size - 10][!type][last]) % MOD;
            ways[size][type][2] = ways[size - 1][type][1];
            ways[size][type][3] = ways[size - 1][type][2];
        }
    }

    int res = 0;
    for (int type = 0; type <= 1; type++)
        for (int last = 1; last <= 3; last++)
            res = (res + ways[targetSize][type][last]) % MOD;

    cout << res;
}