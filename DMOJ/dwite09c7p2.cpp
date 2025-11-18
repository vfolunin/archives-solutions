#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getPrimeSum(int n) {
    vector<int> isPrime(n + 1, 1);
    long long res = 0;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            res += i;
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << getPrimeSum(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 5; i++)
        solve();
}