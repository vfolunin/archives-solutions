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

    int width;
    cin >> width;

    vector<int> primes = getPrimes(3000);

    int sum = 0;
    for (int i = 0; i < width; i++)
        sum += primes[i];

    if (sum == 2011) {
        for (int i = 0; i < width; i++)
            cout << primes[i] << " ";
        return 0;
    }

    for (int i = width; i < primes.size(); i++) {
        sum -= primes[i - width];
        sum += primes[i];

        if (sum == 2011) {
            for (int j = i - width + 1; j <= i; j++)
                cout << primes[j] << " ";
            return 0;
        }
    }

    cout << "NO SOLUTION";
}