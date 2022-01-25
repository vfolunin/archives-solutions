#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    const int N = 1e6 + 2;

    vector<int> isPrime(N);
    for (int i = 5; i < N; i += 4)
        isPrime[i] = 1;

    vector<int> primes;
    for (int i = 5; i < N; i += 4) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }

    vector<int> p(N);
    for (int i = 0; i < primes.size(); i++)
        for (int j = i; j < primes.size() && 1LL * primes[i] * primes[j] < N; j++)
            p[primes[i] * primes[j]] = 1;

    for (int i = 1; i < N; i++)
        p[i] += p[i - 1];
    return p;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> p = prepare();

    cout << n << " " << p[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}