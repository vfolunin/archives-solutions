#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1000;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

void solve() {
    int n, targetSum;
    cin >> n >> targetSum;

    static vector<int> primes = getPrimes();

    vector<int> minDarts(targetSum + 1);
    for (int sum = 0; sum <= targetSum; sum++)
        minDarts[sum] = sum;

    for (int i = 0; i < n - 1; i++)
        for (int sum = 0; sum + primes[i] <= targetSum; sum++)
            minDarts[sum + primes[i]] = min(minDarts[sum + primes[i]], minDarts[sum] + 1);

    cout << minDarts[targetSum] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}