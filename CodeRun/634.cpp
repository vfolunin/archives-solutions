#include <vector>
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

long long solution(int n) {
    vector<int> count(4);
    for (int p : getPrimes(n))
        count[p % count.size()]++;
    return 1LL * count[1] * count[3];
}

