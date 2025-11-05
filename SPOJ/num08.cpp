#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<long long, int> factorize(long long n) {
    map<long long, int> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;
    return factorization;
}

long long getDivisorSum(long long n) {
    long long sum = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n)
                sum += n / d;
        }
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;

    for (auto &[p, k] : factorize(n))
        cout << p << " " << k << "\n";
    cout << "Sum Of Divisiors: " << getDivisorSum(n) << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}