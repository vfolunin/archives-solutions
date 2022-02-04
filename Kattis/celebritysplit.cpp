#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec1(vector<long long> &cost, int i,
          map<long long, long long> &memo,
          long long a, long long b, long long c) {
    if (i == cost.size() / 2) {
        if (!memo.count(a - b) || memo[a - b] > c)
            memo[a - b] = c;
        return;
    }
    rec1(cost, i + 1, memo, a + cost[i], b, c);
    rec1(cost, i + 1, memo, a, b + cost[i], c);
    rec1(cost, i + 1, memo, a, b, c + cost[i]);
}

void rec2(vector<long long> &cost, int i,
          map<long long, long long> &memo,
          long long a, long long b, long long c, long long &res) {
    if (i == cost.size()) {
        if (memo.count(b - a))
            res = min(res, memo[b - a] + c);
        return;
    }
    rec2(cost, i + 1, memo, a + cost[i], b, c, res);
    rec2(cost, i + 1, memo, a, b + cost[i], c, res);
    rec2(cost, i + 1, memo, a, b, c + cost[i], res);
}

bool solve() {
    int mansionCount;
    cin >> mansionCount;

    if (!mansionCount)
        return 0;

    vector<long long> cost(mansionCount);
    for (long long &c : cost)
        cin >> c;

    map<long long, long long> memo;
    rec1(cost, 0, memo, 0, 0, 0);
    long long res = 1LL << 60;
    rec2(cost, cost.size() / 2, memo, 0, 0, 0, res);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}