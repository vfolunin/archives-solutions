#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getIsPrime() {
    const int N = 1e6;
    vector<int> isPrime(N, 1);
    for (int i = 2; i < N; i++)
        if (isPrime[i])
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
    return isPrime;
}

bool hasOnly1379(int n) {
    while (n) {
        if (n % 10 != 1 && n % 10 != 3 && n % 10 != 7 && n % 10 != 9)
            return 0;
        n /= 10;
    }
    return 1;
}

int rotate(int n) {
    string s = to_string(n);
    rotate(s.begin(), s.begin() + 1, s.end());
    return stoi(s);
}

vector<int> getCPrimes() {
    vector<int> cPrimes;
    static vector<int> isPrime = getIsPrime();
    for (int i = 2; i < isPrime.size(); i++) {
        if (i > 9 && !hasOnly1379(i))
            continue;
        bool ok = 1;
        for (int n = i, j = 0; ok && j < 6; n = rotate(n), j++)
            ok &= isPrime[n];
        if (ok)
            cPrimes.push_back(i);
    }
    return cPrimes;
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static vector<int> p = getCPrimes();
    int count = upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l);

    if (count == 0)
        cout << "No Circular Primes.\n";
    else if (count == 1)
        cout << "1 Circular Prime.\n";
    else
        cout << count << " Circular Primes.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}