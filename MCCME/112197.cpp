#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int sum = 1;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n)
                sum += n / d;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        int s = getDivisorSum(i);
        if (l <= s && s < i && getDivisorSum(s) == i) {
            cout << "(" << s << "," << i << ")\n";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}