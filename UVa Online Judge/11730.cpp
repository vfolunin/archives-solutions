#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1001;
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

int moves(int a, int b) {
    static vector<vector<int>> memo(1001, vector<int>(1001, -1));
    if (memo[a][b] != -1)
        return memo[a][b];

    if (a > b)
        return memo[a][b] = 1e9;
    if (a == b)
        return memo[a][b] = 0;

    memo[a][b] = 1e9;

    static vector<int> primes = getPrimes();
    for (int p : primes)
        if (p < a && a % p == 0 && a + p <= b)
            memo[a][b] = min(memo[a][b], 1 + moves(a + p, b));

    return memo[a][b];
}

bool solve(int test) {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    cout << "Case " << test << ": " << (moves(a, b) != 1e9 ? moves(a, b) : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}