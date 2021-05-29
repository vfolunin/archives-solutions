#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long ones(long long n) {
    static vector<long long> memo(1e7, -1);
    if (n < 1e7 && memo[n] != -1)
        return memo[n];

    long long res;
    if (!n)
        res = 0;
    else if (n % 2)
        res = 2 * ones(n / 2) + n / 2 + 1;
    else
        res = ones(n / 2) + ones(n / 2 - 1) + n / 2;

    if (n < 1e7)
        memo[n] = res;
    return res;
}

long long ones(long long l, long long r) {
    return ones(r) - (l ? ones(l - 1) : 0);
}

bool solve(int test) {
    long long l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    cout << "Case " << test << ": " << ones(l, r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}