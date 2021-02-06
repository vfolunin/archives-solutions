#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    if (n < 0) {
        cout << (n % 2 ? "Overflow!\n" : "Underflow!\n");
        return 1;
    }

    long long f = 1;
    for (long long i = 2; i <= n; i++) {
        f *= i;
        if (f > 6227020800LL) {
            cout << "Overflow!\n";
            return 1;
        }
    }

    if (f < 10000)
        cout << "Underflow!\n";
    else
        cout << f << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}