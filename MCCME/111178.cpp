#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int nthPrime(int n) {
    vector<bool> isPrime(2e7, 1);
    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            if (!--n)
                return i;
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << nthPrime(n);
}