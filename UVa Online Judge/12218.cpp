#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> getPrimes() {
    const int N = 1e7;
    vector<int> isPrime(N, 1);
    set<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.insert(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

void solve() {
    string s;
    cin >> s;

    static set<int> primes = getPrimes();

    set<int> nums;
    sort(s.begin(), s.end());
    do {
        int num = 0;
        for (char c : s) {
            num = num * 10 + c - '0';
            if (primes.count(num))
                nums.insert(num);
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << nums.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}