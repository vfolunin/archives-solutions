#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int> isPrime(n + 1, 1), primes;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    return primes;
}

struct DSU {
    vector<int> parent;
    int ccCount;

    DSU(int vertexCount) : ccCount(vertexCount) {
        for (int v = 0; v < vertexCount; v++)
            parent.push_back(v);
    }

    int findRoot(int v) {
        return parent[v] == v ? v : parent[v] = findRoot(parent[v]);
    }

    bool areConnected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    void connect(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB)
            return;
        if (rand() % 2)
            parent[rootA] = rootB;
        else
            parent[rootB] = rootA;
        ccCount--;
    }
};

void solve(int test) {
    long long l, r, threshold;
    cin >> l >> r >> threshold;

    int size = r - l + 1;
    DSU dsu(size);

    for (int prime : getPrimes(size)) {
        if (prime < threshold)
            continue;
        long long lMul = (l + prime - 1) / prime * prime;
        for (long long mul = lMul + prime; mul <= r; mul += prime)
            dsu.connect(lMul - l, mul - l);
    }

    cout << "Case #" << test << ": " << dsu.ccCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}