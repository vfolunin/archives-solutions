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

    int size, limit0, limit1;
    cin >> size >> limit0 >> limit1;

    const int MOD = 1e9 + 7;
    vector ways(2, vector(2, vector<int>(301)));
    ways[1][0][1] = ways[1][1][1] = 1;

    for (int i = 1; i < size; i++) {
        ways[0] = ways[1];
        ways[1].assign(2, vector<int>(301));

        for (int count1 = 1; count1 <= limit1; count1++)
            ways[1][0][1] = (ways[1][0][1] + ways[0][1][count1]) % MOD;
        for (int count0 = 2; count0 <= limit0; count0++)
            ways[1][0][count0] = ways[0][0][count0 - 1];
        for (int count0 = 1; count0 <= limit0; count0++)
            ways[1][1][1] = (ways[1][1][1] + ways[0][0][count0]) % MOD;
        for (int count1 = 2; count1 <= limit1; count1++)
            ways[1][1][count1] = ways[0][1][count1 - 1];
    }

    int res = 0;
    for (int count0 = 1; count0 <= limit0; count0++)
        res = (res + ways[1][0][count0]) % MOD;
    for (int count1 = 1; count1 <= limit1; count1++)
        res = (res + ways[1][1][count1]) % MOD;

    cout << res;
}