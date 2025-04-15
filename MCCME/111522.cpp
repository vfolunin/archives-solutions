#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sumTo(long long r) {
    long long res = 0;
    for (long long d = 2; d <= r; d *= 2)
        res += r / d;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << sumTo(r) - sumTo(l - 1);
}