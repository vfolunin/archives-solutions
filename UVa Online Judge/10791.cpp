#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> factorize(long long n) {
    vector<long long> factorization;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factorization.push_back(1);
            while (n % i == 0) {
                factorization.back() *= i;
                n /= i;
            }
        }
    }
    if (n != 1)
        factorization.push_back(n);
    return factorization;
}

bool solve(int test) {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    vector<long long> f = factorize(n);

    cout << "Case " << test << ": ";
    if (f.size() == 0) {
        cout << 2 << "\n";
    } else if (f.size() == 1) {
        cout << f[0] + 1 << "\n";
    } else {
        long long sum = 0;
        for (long long x : f)
            sum += x;
        cout << sum << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}