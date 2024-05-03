#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getDivisibleCount(long long l, long long r, long long d) {
    if (l > r)
        return getDivisibleCount(r, l, d);
    if (r <= 0)
        return getDivisibleCount(-r, -l, d);

    long long res = r / d;
    if (l > 0)
        res -= (l - 1) / d;
    else
        res += -l / d + 1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r, d;
    cin >> l >> r >> d;

    cout << getDivisibleCount(l, r, d);
}