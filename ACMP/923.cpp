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
    long long &res = memo[n];

    if (n <= 3)
        return res = (n == 3);

    return res = rec(n / 2) + rec((n + 1) / 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << rec(n);
}