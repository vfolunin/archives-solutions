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

bool isPrime(int n) {
    if (n < 2)
        return 0;

    static vector<int> primes = getPrimes(1e4);

    for (int i = 0; primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0)
            return 0;

    return 1;
}

int rec(vector<int> &a, int i, int count, int sum) {
    if (!count)
        return isPrime(sum);

    int res = 0;

    if (i + count < a.size())
        res += rec(a, i + 1, count, sum);

    if (i + 1 <= a.size())
        res += rec(a, i + 1, count - 1, sum + a[i]);

    return res;
}

bool solve() {
    int size, count;
    if (!(cin >> size >> count))
        return 0;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << rec(a, 0, count, 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}