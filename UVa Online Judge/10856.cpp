#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 1e7 + 2;

vector<int> getPrimes() {
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

vector<int> prepare() {
    vector<int> d = { 0 };
    vector<int> primes = getPrimes();
    for (int i = 1; d.back() < N; i++) {
        d.push_back(d.back());
        int n = i;
        for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++) {
            while (n % primes[i] == 0) {
                n /= primes[i];
                d.back()++;
            }
        }
        d.back() += n > 1;
    }
    return d;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (n < 0)
        return 0;

    static vector<int> d = prepare();
    int res = lower_bound(d.begin(), d.end(), n) - d.begin();

    cout << "Case " << test << ": ";
    if (res == d.size() || d[res] != n)
        cout << "Not possible.\n";
    else
        cout << res << "!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}