#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 32000;
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

vector<vector<int>> prepare() {
    vector<int> primes = getPrimes();
    vector<vector<int>> res;
    for (int i = 0; i < primes.size(); ) {
        int j = i + 1;
        while (j + 1 < primes.size() && primes[j + 1] - primes[j] == primes[i + 1] - primes[i])
            j++;
        if (j - i >= 2) {
            res.emplace_back();
            while (i <= j)
                res.back().push_back(primes[i++]);
            i--;
        } else {
            i++;
        }
    }
    return res;
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    if (l > r)
        swap(l, r);

    static vector<vector<int>> res = prepare();
    
    for (vector<int> v : res)
        if (l <= v.front() && v.back() <= r)
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << (i + 1 < v.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}