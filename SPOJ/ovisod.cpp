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

long long getDivisorSum(int n) {
    long long res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res += d;
            if (d * d != n)
                res += n / d;
        }
    }
    return res;
}

void solve() {
    int size;
    cin >> size;

    int gcdValue = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        gcdValue = gcd(gcdValue, value);
    }

    cout << getDivisorSum(gcdValue) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}