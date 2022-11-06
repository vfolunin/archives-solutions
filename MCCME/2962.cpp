#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int y, int x, vector<vector<long long>> &memo) {
    if (y < 0 || y >= memo.size() || x < 0 || x >= memo[0].size())
        return 0;

    long long &res = memo[y][x];
    if (res != -1)
        return res;

    if (!y && !x)
        return res = 1;

    res = 0;
    res += rec(y - 2, x + 1, memo);
    res += rec(y - 2, x - 1, memo);
    res += rec(y - 1, x - 2, memo);
    res += rec(y + 1, x - 2, memo);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<long long>> memo(h, vector<long long>(w, -1));
    cout << rec(h - 1, w - 1, memo);
}