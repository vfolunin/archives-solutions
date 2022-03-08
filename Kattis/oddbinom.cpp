#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(long long n) {
    static vector<long long> memo(1e6);
    if (n < memo.size() && memo[n])
        return memo[n];

    if (n == 1)
        return memo[n] = 1;

    long long res = 2 * rec(n / 2) + rec((n + 1) / 2);
    if (n < memo.size())
        memo[n] = res;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << rec(n);
}