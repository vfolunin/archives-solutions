#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<long long, long long> getSquares(long long n) {
    if (!n)
        return { 0, 0 };

    if (n < 0) {
        auto [a, b] = getSquares(-n);
        return { b, a };
    }

    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;
        long long d2 = n / d;
        if ((d + d2) % 2)
            continue;
        long long a = (d + d2) / 2;
        long long b = (d2 - d) / 2;
        return { a, b };
    }
    return { -1, -1 };
}

long long getBachelorCount(long long r) {
    return r / 4 + (r % 4 >= 2);
}

long long getBachelorCount(long long l, long long r) {
    return getBachelorCount(r) - (l ? getBachelorCount(l - 1) : 0);
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (cin.peek() != ' ') {
        auto [a, b] = getSquares(n);
        if (a != -1)
            cout << a << " " << b << "\n";
        else
            cout << "Bachelor Number.\n";
    } else {
        int l = n, r;
        cin >> r;
        cout << getBachelorCount(l, r) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}