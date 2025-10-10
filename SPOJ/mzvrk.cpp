#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sumTo(long long n) {
    long long sum = 0;
    for (long long p = 1; p <= n; p *= 2)
        sum += p * (n / p - n / (2 * p));
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << sumTo(r) - sumTo(l - 1);
}