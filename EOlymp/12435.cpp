#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPrimeDivisorCount(int n) {
    int primeDivisorCount = 0;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            primeDivisorCount++;
            n /= d;
        }
    }
    primeDivisorCount += n != 1;
    return primeDivisorCount;
}

void solve() {
    int a, b, opCount;
    cin >> a >> b >> opCount;

    if (b % a || a == b && opCount || a != b && (!opCount || getPrimeDivisorCount(b / a) < opCount))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}