#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return factorization;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += factorize(i).size() == 2;

    cout << res;
}