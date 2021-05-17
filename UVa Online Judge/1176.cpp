#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int josephus2(int n) {
    int bit = 30;
    while (!(n & (1 << bit)))
        bit--;
    return 2 * (n - (1 << bit)) + 1;
}

int rec(int n) {
    static vector<int> memo(32768, -1);
    if (memo[n] != -1)
        return memo[n];

    int last = josephus2(n);
    if (last == n)
        return memo[n] = 2 * n;
    return memo[n] = n - last + rec(last);
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