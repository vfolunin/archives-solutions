#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long i, long long d1, long long d2, long long x1, long long x2) {
    if (i <= 0)
        return 1;

    static vector<long long> memo(5e6, -1);
    if (i < memo.size() && memo[i] != -1)
        return memo[i];

    long long res = f(i / d1 - x1, d1, d2, x1, x2) + f(i / d2 - x2, d1, d2, x1, x2);
    if (i < memo.size())
        memo[i] = res;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long i, d1, d2, x1, x2;
    cin >> i >> d1 >> d2 >> x1 >> x2;

    cout << f(i, d1, d2, x1, x2);
}