#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

long long count(long long size, long long r) {
    if (!size)
        return 1;
    long long half = 1LL << (size - 1);
    if (r < half)
        return 2 * count(size - 1, r);
    else
        return 2 * binPow(3, size - 1) + count(size - 1, r - half);
}

void solve(int test) {
    long long size, l, r;
    cin >> size >> l >> r;
    
    l--;
    r--;
    long long res = count(size, r) - (l ? count(size, l - 1) : 0);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}