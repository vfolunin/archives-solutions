#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> f;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            f[d]++;
            n /= d;
        }
    }
    if (n > 1)
        f[n]++;
    return f;
}

vector<long long> prepare() {
    vector<long long> lcmLast = { 0, 1 };
    map<int, int> lcm;

    for (int i = 2; i <= 1e6; i++) {
        lcmLast.push_back(lcmLast.back());
        map<int, int> f = factorize(i);

        for (auto &[prime, power] : f) {
            while (lcm[prime] < power) {
                lcm[prime]++;
                lcmLast.back() *= prime;
                while (lcmLast.back() % 10 == 0)
                    lcmLast.back() /= 10;
                lcmLast.back() %= (long long)1e10;
            }
        }
    }

    return lcmLast;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> lcm = prepare();
    
    cout << lcm[n] % 10 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}