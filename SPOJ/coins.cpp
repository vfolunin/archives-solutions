#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int n) {
    static vector<long long> memo(1e7, -1);
    if (n < memo.size() && memo[n] != -1)
        return memo[n];

    if (!n)
        return memo[n] = 0;

    long long res = max<long long>(n, rec(n / 2) + rec(n / 3) + rec(n / 4));
    if (n < memo.size())
        memo[n] = res;
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << rec(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}