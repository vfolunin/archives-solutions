#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(int n, int d) {
    int res = 0;
    while (n) {
        res += n % 10 == d;
        n /= 10;
    }
    return res;
}

int countTo(int n, int d) {
    int res = 0;
    if (n < 10) {
        while (n) {
            res += count(n, d);
            n--;
        }
    } else {
        while (n % 10 != 9) {
            res += count(n, d);
            n--;
        }
        res += n / 10 + (bool)d + countTo(n / 10, d) * 10;
    }
    return res;
}

int count(int l, int r, int d) {
    return countTo(r, d) - countTo(l - 1, d);
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    if (l > r)
        swap(l, r);

    for (int i = 0; i < 10; i++)
        cout << count(l, r, i) << (i < 9 ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}