#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e5;
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

bool solve() {
    string line;
    cin >> line;

    if (line == "0")
        return 0;

    static vector<int> primes = getPrimes();

    int res = -1;
    for (int i = 0; i < line.size(); i++) {
        int p = 0;
        for (int j = i; j < line.size() && p <= 1e5; j++) {
            p = p * 10 + line[j] - '0';
            if (binary_search(primes.begin(), primes.end(), p))
                res = max(res, p);
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}