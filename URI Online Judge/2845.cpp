#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getMinDivisor() {
    const int N = 1e6 + 1;
    vector<int> minDivisor(N), primes;
    for (int i = 2; i < N; i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < N; j++)
            minDivisor[i * primes[j]] = primes[j];
    }
    return minDivisor;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int coprimeCount;
    cin >> coprimeCount;

    vector<int> coprimes(coprimeCount);
    for (int &p : coprimes)
        cin >> p;
    sort(coprimes.begin(), coprimes.end());

    vector<int> minDivisor = getMinDivisor();
    int res = coprimes.back() + 1;
    while (binary_search(coprimes.begin(), coprimes.end(), minDivisor[res]))
        res++;

    cout << res << "\n";
}