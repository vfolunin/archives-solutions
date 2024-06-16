#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitMask(long long n) {
    int res = 0;
    while (n) {
        res |= 1 << n % 10;
        n /= 10;
    }
    return res;
}

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    int has = 0;
    for (int i = 1; 1; i++) {
        has |= digitMask(n * i);
        if (has == (1 << 10) - 1) {
            cout << i << "\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}