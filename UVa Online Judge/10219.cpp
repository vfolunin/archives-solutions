#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n, k;
    if (!(cin >> n >> k))
        return 0;

    long double logF = 0;
    for (long long i = n - k + 1; i <= n; i++)
        logF += log10l(i);
    for (long long i = 1; i <= k; i++)
        logF -= log10l(i);

    cout << (int)logF + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}