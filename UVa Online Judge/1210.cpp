#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes(int limit) {
    vector<bool> isPrime(limit, 1);
    vector<int> primes;
    for (int i = 2; i < limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < limit; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

vector<int> prepare(int limit) {
    vector<int> p = getPrimes(limit);
    vector<int> sums(limit);
    for (int i = 0; i < p.size(); i++) {
        int sum = 0;
        for (int j = i; j < p.size(); j++) {
            sum += p[j];
            if (sum < limit)
                sums[sum]++;
        }
    }
    return sums;
}

bool solve() {
    static vector<int> sums = prepare(1e4 + 1);

    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << sums[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}