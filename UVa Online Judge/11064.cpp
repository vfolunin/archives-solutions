#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long phi(long long n) {
    long long res = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

long long divisorCount(long long n) {
    long long count = 1;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            count += (i * i != n);                
        }
    }
    return count;
}

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    cout << n + 2 - phi(n) - divisorCount(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}