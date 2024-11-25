#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(int d, int r) {
    return r / d;
}

int count(int d, int l, int r) {
    if (l > 0)
        return count(d, r) - count(d, l - 1);
    else
        return count(d, abs(l)) - count(d, abs(r) - 1);
}

int totalCount(int d, int l, int r) {
    if (l <= 0 && 0 <= r)
        return 1;

    int res = 0;
    for (long long power = d; power <= 2e9; power *= d)
        res += count(power, l, r);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    cout << min(totalCount(2, l, r), totalCount(5, l, r));
}