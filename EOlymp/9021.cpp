#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long solve(long long r) {
    long long res = 0;
    for (long long p2 = 1; p2 <= r; p2 *= 2)
        for (long long p3 = 1; p2 * p3 <= r; p3 *= 3)
            res++;
    return res;
}

long long solve(long long l, long long r) {
    return solve(r) - (l ? solve(l - 1) : 0);
}

bool solve() {
    long long l, r;
    if (!(cin >> l >> r))
        return 0;

    cout << solve(l, r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}