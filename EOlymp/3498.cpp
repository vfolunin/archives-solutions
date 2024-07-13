#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

vector<int> getPrimes() {
    vector<int> primes;
    for (int i = 2; i <= 1120; i++)
        if (isPrime(i))
            primes.push_back(i);
    return primes;
}

int rec(int sum, int cnt, int last) {
    static vector<int> primes = getPrimes();
    if (last >= primes.size())
        return 0;

    static vector<vector<vector<int>>> memo(1121, vector<vector<int>>(15, vector<int>(primes.size(), -1)));
    if (memo[sum][cnt][last] != -1)
        return memo[sum][cnt][last];

    if (sum < primes[last])
        return memo[sum][cnt][last] = 0;

    if (cnt == 1)
        return memo[sum][cnt][last] = (sum == primes[last]);

    int res = 0;
    for (int prevLast = 0; prevLast < last; prevLast++)
        res += rec(sum - primes[last], cnt - 1, prevLast);
    return memo[sum][cnt][last] = res;
}

bool solve() {
    int n, k;
    cin >> n >> k;

    if (!n && !k)
        return 0;

    long long res = 0;
    for (int last = 0; last < 200; last++)
        res += rec(n, k, last);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}