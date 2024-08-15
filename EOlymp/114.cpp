#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int> isPrime(n + 1, 1), primes;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    return primes;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit;

    vector<int> primes = getPrimes(3 * limit);
    long long res = 0;

    for (int a = 1; a <= limit; a++) {
        for (int b = 1, l = 0, r = 0; b <= limit; b++) {
            while (primes[l] <= a + b)
                l++;
            while (r < primes.size() && primes[r] <= a + b + limit)
                r++;
            res += r - l;
        }
    }
    
    cout << res;
}