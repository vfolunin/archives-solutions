#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    map<int, int> divisors;
    for (auto &[d, p] : factorize(a))
        divisors[d] += p;
    for (auto &[d, p] : factorize(b))
        divisors[d] -= p;

    int res = 0;
    for (auto &[d, p] : divisors)
        res += abs(p);

    cout << res;
}