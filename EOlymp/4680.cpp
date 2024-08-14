#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void factorize(int n, map<int, int> &factorization) {
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    map<int, int> factorization;
    for (int i = 2; i <= n; i++)
        factorize(i, factorization);

    int res = 1;
    for (auto &[_, count] : factorization)
        res *= count + 1;

    cout << res;
}