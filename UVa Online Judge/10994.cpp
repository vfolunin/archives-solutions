#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(long long l, long long r) {
    long long res = 0;
    while (1) {
        while (l < r && l % 10) {
            res += l % 10;
            l++;
        }

        while (l < r && r % 10) {
            res += r % 10;
            r--;
        }

        if (l % 10 == 0) {
            l /= 10;
            r /= 10;
        }

        if (l < r) {
            res += (r - l) * 45;
        } else {
            res += l % 10;
            break;
        }
    }
    return res;
}

bool solve() {
    long long l, r;
    cin >> l >> r;

    if (l < 0 && r < 0)
        return 0;

    cout << sum(l, r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}