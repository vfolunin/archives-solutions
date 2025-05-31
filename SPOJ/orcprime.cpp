#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPrimeDivisors(long long n) {
    vector<long long> primeDivisors;

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            primeDivisors.push_back(d);
            while (n % d == 0)
                n /= d;
        }
    }
    if (n != 1)
        primeDivisors.push_back(n);

    return primeDivisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    for (long long p : getPrimeDivisors(n))
        cout << p << "\n";
}