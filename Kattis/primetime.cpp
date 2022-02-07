#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 2e5;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

vector<int> rec(int n) {
    static vector<vector<int>> memo(2e5);
    vector<int> &res = memo[n];
    if (!res.empty())
        return res;

    res.assign(3, 1e9);

    static vector<int> primes = getPrimes();
    for (int i = 0; primes[i] <= n; i++) {
        if (n % primes[i])
            continue;

        vector<int> recRes = rec(n / primes[i]);
        if (min(n / primes[i], recRes[2]) <= res[0])
            res = { min(n / primes[i], recRes[2]), recRes[0], recRes[1] };
    }

    if (!binary_search(primes.begin(), primes.end(), n)) {
        vector<int> recRes = rec(n + 1);
        if (recRes[2] < res[0])
            res = { recRes[2], recRes[0], recRes[1] };
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int roundCount;
    cin >> roundCount;

    string names = "OEI";
    vector<int> totalScore(3);

    for (int i = 0; i < roundCount; i++) {
        char name;
        int n;
        cin >> name >> n;

        vector<int> roundScore = rec(n);
        int shift = names.find(name);
        for (int j = 0; j < 3; j++)
            totalScore[(shift + j) % 3] += min(roundScore[j], n);
    }

    for (int i = 0; i < 3; i++)
        cout << totalScore[i] << (i < 2 ? " " : "\n");
}