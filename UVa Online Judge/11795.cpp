#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int mask, vector<string> &wins, vector<long long> &memo) {
    long long &res = memo[mask];
    if (res != -1)
        return res;

    if (mask == 1)
        return res = 1;

    res = 0;
    for (int last = 1; last < wins.size(); last++) {
        if (!(mask & (1 << last)))
            continue;

        int ok = 0;
        for (int prev = 0; !ok && prev < wins.size(); prev++)
            ok |= last != prev && (mask & (1 << prev)) && wins[prev][last - 1] == '1';

        if (ok)
            res += rec(mask ^ (1 << last), wins, memo);
    }
    return res;
}

void solve(int test) {
    int robotCount;
    cin >> robotCount;

    vector<string> wins(robotCount + 1);
    for (string &w : wins)
        cin >> w;

    vector<long long> memo(1 << (robotCount + 1), -1);
    long long res = rec((1 << (robotCount + 1)) - 1, wins, memo);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}