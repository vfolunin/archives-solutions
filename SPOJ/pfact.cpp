#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> minDivisor(1e5 + 1), primes;
    for (int i = 2; i < minDivisor.size(); i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < minDivisor.size(); j++)
            minDivisor[i * primes[j]] = primes[j];
    }
    return minDivisor;
}

void printDivisors(int n) {
    if (n == 1)
        return;

    static vector<int> minDivisor = prepare();
    int d = minDivisor[n];
    while (n % d == 0)
        n /= d;

    cout << d << " ";
    printDivisors(n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);

    for (int i = 2; i <= 1e5; i++) {
        cout << i << ": ";
        printDivisors(i);
        cout << "\n";
    }
}