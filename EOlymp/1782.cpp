#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<int, int>> factorize(long long n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return { factorization.begin(), factorization.end() };
}

long long rec(const vector<pair<int, int>> &factors, int i, long long divisor) {
    if (i == factors.size())
        return divisor;

    long long res = rec(factors, i + 1, divisor);

    long long factor = 1;
    for (int j = 0; j < factors[i].second; j++) {
        factor *= factors[i].first;
        res += rec(factors, i + 1, divisor * factor);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << rec(factorize(n), 0, 1);
}