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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    map<long long, int> factorization = factorize(n);
    long long res = factorization.begin()->first;

    for (auto &[d, count] : factorization)
        if (factorization[res] < count)
            res = d;
    
    cout << res;
}