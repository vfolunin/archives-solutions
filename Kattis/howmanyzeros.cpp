#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int zerosIn(long long n) {
    int res = 0;
    while (n) {
        res += n % 10 == 0;
        n /= 10;
    }
    return res;
}

long long zerosTo(long long n) {
    if (n <= 9)
        return 0;

    long long res = 0;
    while (n % 10 != 9) {
        res += zerosIn(n);
        n--;
    }

    if (n > 9)
        res += zerosTo(n / 10) * 10 + n / 10;

    return res;
}

bool solve() {
    long long l, r;
    cin >> l >> r;

    if (l == -1 && r == -1)
        return 0;

    long long res = zerosTo(r);
    if (l)
        res -= zerosTo(l - 1);
    else
        res++;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}