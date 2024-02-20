#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int lastDigit(int n) {
    while (n > 9 && n % 10 == 0)
        n /= 10;
    return n % 10;
}

long long lastDigitSumTo(int n) {
    if (n <= 0)
        return 0;

    long long res = 0;

    while (1) {
        res += lastDigit(n);
        if (n % 10)
            n--;
        else
            break;
    }
    n /= 10;

    return res + n * 45LL + lastDigitSumTo(n - 1);
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (l < 0)
        return 0;

    cout << lastDigitSumTo(r) - lastDigitSumTo(l - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}