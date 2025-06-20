#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int rec(int n) {
    static unordered_map<int, int> memo;
    if (memo.count(n) || n == 1)
        return memo[n];
    int &res = memo[n] = -1;

    int nextN = 0;
    for (; n; n /= 10)
        nextN += (n % 10) * (n % 10);

    int nextRes = rec(nextN);
    if (nextRes != -1)
        res = 1 + nextRes;
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << rec(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}