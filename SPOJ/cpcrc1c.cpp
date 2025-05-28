#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long count(int n, int digit) {
    int res = 0;
    while (n) {
        res += n % 10 == digit;
        n /= 10;
    }
    return res;
}

long long countTo(int n, int digit) {
    long long res = 0;
    if (n < 10) {
        while (n) {
            res += count(n, digit);
            n--;
        }
    } else {
        while (n % 10 != 9) {
            res += count(n, digit);
            n--;
        }
        res += n / 10 + (bool)digit + countTo(n / 10, digit) * 10;
    }
    return res;
}

long long count(int l, int r, int digit) {
    return countTo(r, digit) - (l ? countTo(l - 1, digit) : 0);
}

bool solve() {
    int l, r;
    cin >> l >> r;
    if (l == -1)
        return 0;

    long long res = 0;
    for (int digit = 1; digit <= 9; digit++)
        res += digit * count(l, r, digit);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}