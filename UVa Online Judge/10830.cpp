#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long n;
    if (!(cin >> n) || !n)
        return 0;

    long long csod = 0;   
    for (long long d = 2; d * d <= n; d++) {
        csod += d * (n / d - 1);
        long long l = n / (d + 1) + 1, r = n / d;
        if (d < l)
            csod += (l + r) * (r - l + 1) / 2 * (d - 1);
    }

    cout << "Case " << test << ": " << csod << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}