#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> getDivisorCount(int n) {
    vector<int> minDivisor(n + 1), primes, divisorCount(n + 1, 1);

    for (int i = 2; i < minDivisor.size(); i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < minDivisor.size(); j++)
            minDivisor[i * primes[j]] = primes[j];

        unordered_map<int, int> factorization;
        for (int j = i; j > 1; j /= minDivisor[j])
            factorization[minDivisor[j]]++;
        
        for (auto &[_, count] : factorization)
            divisorCount[i] *= count + 1;
    }

    return divisorCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> divisorCount = getDivisorCount(n);

    for (int i = 1; i <= n; i++)
        cout << divisorCount[i] << "\n";
}