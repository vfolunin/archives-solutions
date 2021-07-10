#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int divisorCount(long long n) {
    int res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;
        res++;
        res += d * d < n;
    }
    return res;
}

bool solve(int test) {
    long long m, n, p;
    if (!(cin >> m >> n >> p) || !m && !n && !p)
        return 0;

    long long res = divisorCount(abs(m * n * p * p)) * 2 - 1;

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}