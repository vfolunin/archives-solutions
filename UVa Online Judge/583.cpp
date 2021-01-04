#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    cout << n << " = ";
    bool first = 1;

    if (n < 0) {
        cout << -1;
        first = 0;
        n = -n;
    }

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            if (first)
                first = 0;
            else
                cout << " x ";
            cout << d;
            n /= d;
        }
    }
    
    if (n > 1) {
        if (!first)
            cout << " x ";
        cout << n;
    }
    cout << "\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}