#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 3e5;
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

struct Matrix {
    long double a, b, c, d;
};

Matrix mul(const Matrix &m1, const Matrix &m2) {
    long double a = m1.a * m2.a + m1.b * m2.c;
    long double b = m1.a * m2.b + m1.b * m2.d;
    long double c = m1.c * m2.a + m1.d * m2.c;
    long double d = m1.c * m2.b + m1.d * m2.d;

    while (b >= 1e9) {
        a /= 10;
        b /= 10;
        c /= 10;
        d /= 10;
    }

    return { a, b, c, d };
}

Matrix binPow(const Matrix &m, int p) {
    if (!p)
        return { 1, 0, 0, 1 };
    if (p % 2)
        return mul(binPow(m, p - 1), m);
    Matrix r = binPow(m, p / 2);
    return mul(r, r);
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (n <= 2) {
        cout << n + 1 << "\n";
        return 1;
    }

    static vector<int> primes = getPrimes();

    int res = binPow({ 0, 1, 1, 1 }, primes[n - 1]).b;
    while (res >= 1e9)
        res /= 10;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}