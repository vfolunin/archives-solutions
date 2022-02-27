#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    set<long long> divisors;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.insert(d);
            divisors.insert(n / d);
        }
    }

    for (long long d : divisors)
        cout << d - 1 << " ";
}