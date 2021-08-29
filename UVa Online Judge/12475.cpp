#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long double a, b;
    cin >> a >> b;

    long double e = sqrtl(1 - (a * a) / (b * b));

    long double res = 1, num = 1, den = 2;
    for (int i = 1; i <= 1000; i++) {
        res -= powl(num / den, 2) * powl(e, 2 * i) / (2 * i - 1);
        num *= 2 * i + 1;
        den *= 2 * i + 2;
    }
    res *= 2 * acosl(-1) * b;

    cout << "Case " << test << ": " << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}