#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long oddSum(long long r) {
    if (r < 0)
        return -oddSum(-r);
    r = (r + 1) / 2;
    return r * r;
}

long long oddSum(long long l, long long r) {
    if (l > r)
        return oddSum(r, l);
    if (r < 0)
        return -oddSum(-r, -l);
    long long res = oddSum(r);
    if (l > 0)
        res -= oddSum(l - 1);
    else
        res += oddSum(l);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << oddSum(l, r);
}