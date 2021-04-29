#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c, d;
    if (!(cin >> a >> b >> c >> d))
        return 0;

    multiset<int> num, den;

    for (int i = 1; i <= a; i++)
        num.insert(i);
    for (int i = 1; i <= b; i++)
        den.insert(i);
    for (int i = 1; i <= a - b; i++)
        den.insert(i);

    for (int i = 1; i <= c; i++)
        den.insert(i);
    for (int i = 1; i <= d; i++)
        num.insert(i);
    for (int i = 1; i <= c - d; i++)
        num.insert(i);

    double res = 1;
    while (!num.empty() || !den.empty()) {
        while (!num.empty() && (den.empty() || res < 1e8)) {
            res *= *num.begin();
            num.erase(num.begin());
        }
        while (!den.empty() && (num.empty() || res > 1e-8)) {
            res /= *den.begin();
            den.erase(den.begin());
        }
    }

    cout.precision(5);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}