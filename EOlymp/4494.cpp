#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long rec(int n) {
    static unordered_map<int, long long> memo;
    if (memo.count(n))
        return memo[n];
    long long &res = memo[n];

    if (n == 1)
        return res = 1;

    long long a = rec(n / 2);
    long long b = rec(n - n / 2);
    return res = a * b * (n % 2 + 1) % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << rec(n);
}