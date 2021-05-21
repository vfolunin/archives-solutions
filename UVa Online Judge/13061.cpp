#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 9999959999LL;

long long rec(int a, int b) {
    static vector<vector<long long>> memo(2001, vector<long long>(2001, -1));
    if (memo[a][b] != -1)
        return memo[a][b];

    memo[a][b] = 1;
    if (a)
        memo[a][b] = (memo[a][b] + rec(a - 1, b + 1)) % MOD;
    if (b)
        memo[a][b] = (memo[a][b] + rec(a, b - 1)) % MOD;
    return memo[a][b];
}

bool solve() {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    cout << rec(a, b) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}