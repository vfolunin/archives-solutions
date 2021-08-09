#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long rec(int stones, int boxes, int overflowStones) {
    static vector<vector<vector<long long>>> memo(201, vector<vector<long long>>(101, vector<long long>(201, -1)));
    long long &res = memo[stones][boxes][overflowStones];
    if (res != -1)
        return res;

    if (!stones && !overflowStones)
        return res = 1;

    if (!boxes)
        return res = 0;

    res = 0;
    for (int placedStones = 0; placedStones <= stones; placedStones++)
        res = (res + rec(stones - placedStones, boxes - 1, (overflowStones + placedStones) / 2)) % MOD;
    return res;
}

bool solve() {
    int stones, boxes;
    if (!(cin >> stones >> boxes))
        return 0;

    cout << rec(stones, boxes - 1, 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}