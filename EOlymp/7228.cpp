#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(int n, int digit) {
    int res = 0;
    while (n) {
        res += n % 10 == digit;
        n /= 10;
    }
    return res;
}

int countTo(int n, int digit) {
    int res = 0;
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

int count(int l, int r, int digit) {
    return countTo(r, digit) - countTo(l - 1, digit);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);

    cout << count(l, r, 6);
}