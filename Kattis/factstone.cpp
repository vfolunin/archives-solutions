#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int year;
    cin >> year;

    if (!year)
        return 0;

    int bits = (year - 1960) / 10 + 2;
    int limit = 1 << bits;

    int res = 1;
    double logSum = 0;
    while (logSum < limit)
        logSum += log(res++) / log(2);
    res -= 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}