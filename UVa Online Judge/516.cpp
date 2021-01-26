#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    vector<bool> isPrime(1e5, 1);
    vector<int> primes;
    for (int i = 2; i < 1e5; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < 1e5; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

vector<int> readVector() {
    vector<int> v;
    do {
        v.emplace_back();
        cin >> v.back();
    } while (cin.get() == ' ');
    return v;
}

void writeVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
}

bool solve() {
    vector<int> v = readVector();
    if (!v[0])
        return 0;

    int n = 1;
    for (int i = 0; i < v.size(); i += 2)
        for (int j = 0; j < v[i + 1]; j++)
            n *= v[i];
    n--;

    static vector<int> primes = getPrimes();

    vector<int> res;
    for (int i = primes.size() - 1; i >= 0; i--) {
        if (n % primes[i] == 0) {
            res.push_back(primes[i]);
            res.push_back(0);
            while (n % primes[i] == 0) {
                n /= primes[i];
                res.back()++;
            }
        }
    }

    writeVector(res);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}