#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(long long n, int a, int b) {
    static vector<long long> memo(1e6, -1);
    if (n < memo.size() && memo[n] != -1)
        return memo[n];

    if (!n)
        return memo[n] = 1;

    long long res = rec(n / a, a, b) + rec(n / b, a, b);
    if (n < memo.size())
        memo[n] = res;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    int a, b;
    cin >> n >> a >> b;

    cout << rec(n, a, b);
}