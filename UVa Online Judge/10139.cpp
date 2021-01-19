#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factorialPow(int f, int d) {
    int res = 0;
    while (f) {
        f /= d;
        res += f;
    }
    return res;
}

bool dividesFactorial(int f, int d) {
    if (!d)
        return 1;
    for (long long i = 2; i * i <= d; i++) {
        if (d % i)
            continue;
        int p = 0;
        while (d % i == 0) {
            p++;
            d /= i;
        }
        if (factorialPow(f, i) < p)
            return 0;
    }
    return d == 1 || factorialPow(f, d) >= 1;
}

bool solve() {
    int f, d;
    if (!(cin >> f >> d))
        return 0;

    if (dividesFactorial(f, d))
        cout << d << " divides " << f << "!\n";
    else
        cout << d << " does not divide " << f << "!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}