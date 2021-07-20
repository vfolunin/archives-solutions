#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPrimes() {
    const int N = 100000;
    vector<int> isPrime(N, 1);
    vector<long long> primes;
    for (long long i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve() {
    long long maxArea, num, den;
    cin >> maxArea >> num >> den;

    if (!maxArea)
        return 0;

    static vector<long long> primes = getPrimes();

    long long bestP, bestQ, bestArea = -1;
    for (long long p : primes) {
        if (p * p > maxArea)
            break;

        long long q = *--upper_bound(primes.begin(), primes.end(), min(maxArea / p, p * den / num));
        if (bestArea < p * q) {
            bestArea = p * q;
            bestP = p;
            bestQ = q;
        }
    }

    cout << bestP << " " << bestQ << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}