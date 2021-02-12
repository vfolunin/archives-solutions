#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int collatz(long long n) {
    static unordered_map<long long, int> memo;
    if (memo.count(n))
        return memo[n];

    if (n == 1)
        return memo[n] = 1;

    if (n % 2)
        return memo[n] = 1 + collatz(3 * n + 1);
    else
        return memo[n] = 1 + collatz(n / 2);
}

vector<int> prepare() {
    vector<int> res(1000000);
    for (int i = 1; i < res.size(); i++)
        res[i] = collatz(i);
    return res;
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    cout << l << " " << r << " ";
    if (l > r)
        swap(l, r);

    static vector<int> res = prepare();
    cout << *max_element(res.begin() + l, res.begin() + r + 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}