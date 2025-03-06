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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 1 + n / 10;
    for (int digit = 0; digit <= 9; digit++)
        res += countTo(n / 10, digit);
    if (n % 10 && n > 1)
        for (int digit = 0; digit <= 9; digit++)
            res += count(n, digit);

    cout << res;
}