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

struct HighlyCompositeNumber {
    long long value, divisorCount;
    vector<int> primePowers;

    HighlyCompositeNumber getMultiple(int i, int prime) {
        HighlyCompositeNumber res = *this;
        res.value *= prime;
        if (i < res.primePowers.size()) {
            res.divisorCount /= (res.primePowers[i] + 1);
            res.primePowers[i]++;
        } else {
            res.primePowers.push_back(1);
        }
        res.divisorCount *= (res.primePowers[i] + 1);
        return res;
    }

    bool operator < (const HighlyCompositeNumber &that) const {
        return value < that.value;
    }
};

vector<long long> getHighlyCompositeNumbers() {
    vector<int> primes = getPrimes(100);

    set<HighlyCompositeNumber> q = { { 1, 1, {} } };
    vector<long long> res;

    while (!q.empty()) {
        HighlyCompositeNumber cur = *q.begin();
        q.erase(q.begin());
        res.push_back(cur.value);
        
        while (!q.empty() && cur.divisorCount >= q.begin()->divisorCount)
            q.erase(q.begin());

        for (int i = 0; i <= cur.primePowers.size(); i++)
            if ((long long)1e18 / primes[i] >= cur.value)
                q.insert(cur.getMultiple(i, primes[i]));
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    vector<long long> a = getHighlyCompositeNumbers();

    for (int i = 0; i < queryCount; i++) {
        long long l, r;
        cin >> l >> r;

        cout << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << "\n";
    }
}