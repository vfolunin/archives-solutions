#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

long long onesTo(long long n) {
    if (!n)
        return 0;

    if (n % 2)
        return onesTo(n / 2) * 2 + (n + 1) / 2;
    else
        return onesTo(n - 1) + ones(n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << onesTo(r) - onesTo(l - 1);
}