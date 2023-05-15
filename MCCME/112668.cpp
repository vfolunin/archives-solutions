#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long phi(long long n) {
    long long res = n;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            res -= res / d;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << phi(n);
}