#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e6;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> primes = getPrimes();

    long long pairCount = 0;
    for (int l = 0, r = primes.size() - 1; l < r; l++) {
        while (l < r && primes[l] + primes[r] > n)
            r--;
        if (l < r)
            pairCount += r - l;
    }

    cout << "Case " << test << ": " << pairCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}