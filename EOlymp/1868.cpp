#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(long long n) {
    static map<long long, long long> memo;
    if (memo.count(n))
        return memo[n];

    if (n <= 2)
        return memo[n] = 1;

    long long res;
    if (n % 2)
        res = rec(n * 6 / 7) + rec(n * 2 / 3);
    else
        res = rec(n - 1) + rec(n - 3);
    res %= 0x100000000;

    return memo[n] = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << rec(n);
}