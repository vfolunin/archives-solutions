#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getProperDivisorSum(int n) {
    int sum = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n)
                sum += n / d;
        }
    }
    return sum - n;
}

void solve() {
    int n;
    cin >> n;

    int divisorSum = getProperDivisorSum(n);

    if (divisorSum < n)
        cout << n << " is a deficient number.\n";
    else if (divisorSum == n)
        cout << n << " is a perfect number.\n";
    else
        cout << n << " is an abundant number.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}