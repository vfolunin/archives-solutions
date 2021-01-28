#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int a, b;
    cin >> b;

    if (!b)
        return 0;

    int d = 0;
    while (1) {
        a = b;
        cin >> b;
        if (b)
            d = gcd(d, abs(b - a));
        else
            break;
    }

    cout << d << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}