#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int rec(int n) {
    static unordered_map<int, int> memo;
    if (memo.count(n))
        return memo[n];

    return memo[n] = n ? rec(n / 2) + rec(n / 5) + rec(n / 7) : 1;
}

void solve() {
    int n;
    cin >> n;

    cout << rec(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}