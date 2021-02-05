#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    vector<int> isPrime(1000, 1);
    vector<int> primes = { 1 };
    for (int i = 2; i < 1000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < 1000; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve() {
    int n, c;
    if (!(cin >> n >> c))
        return 0;

    static vector<int> primes = getPrimes();
    int size = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    int center = size / 2;
    int l = max(0, center - c + size % 2);
    int r = min(size - 1, center + c - 1);

    cout << n << " " << c << ":";
    for (int i = l; i <= r; i++)
        cout << " " << primes[i];
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}