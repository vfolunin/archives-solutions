#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long count(long long n, int digit) {
    long long res = 0;
    while (n) {
        res += n % 10 == digit;
        n /= 10;
    }
    return res;
}

long long countTo(long long n, int digit) {
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

long long count(long long l, long long r, int digit) {
    return countTo(r, digit) - countTo(l - 1, digit);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    long long res = 0;
    for (int digit = 0; digit <= 9; digit++)
        res += count(l, r, digit) * digit;

    cout << res;
}