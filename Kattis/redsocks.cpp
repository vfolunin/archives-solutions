#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    long long num, den;
    cin >> num >> den;

    if (!num && !den)
        return 0;

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    for (long long total = 2; total <= 50000; total++) {
        long long redSquared = total * (total - 1) * num;
        if (redSquared % den)
            continue;
        redSquared /= den;

        long long red = sqrt(redSquared);
        while (red * (red - 1) < redSquared)
            red++;
        while (red * (red - 1) > redSquared)
            red--;
        if (red * (red - 1) == redSquared) {
            cout << red << " " << total - red << "\n";
            return 1;
        }
    }

    cout << "impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}