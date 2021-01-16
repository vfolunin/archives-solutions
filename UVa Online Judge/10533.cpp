#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 9) {
        sum += n % 10;
        n /= 10;
    }
    return sum + n;
}

vector<int> getDigitPrimes() {
    vector<bool> isPrime(1e6, 1);
    vector<int> digitPrimes;
    for (long long i = 2; i < 1e6; i++) {
        if (isPrime[i]) {
            if (isPrime[digitSum(i)])
                digitPrimes.push_back(i);
            for (long long j = i * i; j < 1e6; j += i)
                isPrime[j] = 0;
        }
    }
    return digitPrimes;
}

void solve() {
    static vector<int> p = getDigitPrimes();    
    int l, r;
    cin >> l >> r;
    cout << upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}