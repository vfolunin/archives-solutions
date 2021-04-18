#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 2e6 + 1;

vector<int> getMinDivisor() {
    vector<int> minDivisor(N), primes;
    for (int i = 2; i < N; i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < N; j++)
            minDivisor[i * primes[j]] = primes[j];
    }
    return minDivisor;
}

int factorCount(int n) {
    static vector<int> minDivisor = getMinDivisor();
    int res = 0;
    while (n > 1) {
        res++;
        n /= minDivisor[n];
    }
    return res;
}

vector<int> getFactorCount() {
    vector<int> fc(N);
    for (int i = 2; i < N; i++)
        fc[i] = factorCount(i);
    return fc;
}

bool compare(int a, int b) {
    static vector<int> fc = getFactorCount();
    return fc[a] < fc[b] || fc[a] == fc[b] && a < b;
}

vector<int> prepare() {
    vector<int> p(N);
    for (int i = 0; i < N; i++)
        p[i] = i;
    sort(p.begin() + 1, p.end(), compare);
    return p;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> p = prepare();

    cout << "Case " << test << ": " << p[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}