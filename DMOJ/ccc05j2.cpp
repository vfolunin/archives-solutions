#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int divisorCount = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisorCount++;
            divisorCount += d * d != n;
        }
    }
    return divisorCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int count = 0;
    for (int i = l; i <= r; i++)
        count += getDivisorCount(i) == 4;

    cout << "The number of RSA numbers between " << l << " and " << r << " is " << count;
}