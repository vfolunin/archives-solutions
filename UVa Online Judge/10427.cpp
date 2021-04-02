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

    if (n < 10) {
        cout << n << "\n";
        return 1;
    }
    n -= 10;

    long long len = 2, count = 90;
    while (n >= count * len) {
        n -= count * len;
        len++;
        count *= 10;
    }

    long long number = 1;
    for (int i = 1; i < len; i++)
        number *= 10;
    number += n / len;

    n = len - 1 - n % len;
    for (int i = 0; i < n; i++)
        number /= 10;

    cout << number % 10 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}