#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int> minDivisor(n + 1), primes;

    for (int i = 2; i < minDivisor.size(); i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < minDivisor.size(); j++)
            minDivisor[i * primes[j]] = primes[j];
    }

    return primes;
}

void solve() {
    int value;
    cin >> value;

    static vector<int> primes = getPrimes(1e8);
    int index = lower_bound(primes.begin(), primes.end(), value) - primes.begin();

    if (index == primes.size() || primes[index] != value) {
        cout << "-1\n";
        return;
    }

    int row = 0;
    while (index >= row + 1) {
        row++;
        index -= row;
    }

    cout << row + 1 << " " << index + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}