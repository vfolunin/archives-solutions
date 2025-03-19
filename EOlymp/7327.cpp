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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= 9; i++)
        res += n >= binPow(i, i);
    res += n >= binPow(2, binPow(2, 2));
    res += n >= binPow(2, binPow(2, binPow(2, 2)));

    cout << res;
}