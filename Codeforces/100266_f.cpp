#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int res = 0;
    for (long long d = 1; d * d <= n; d++)
        if (n % d == 0)
            res += 1 + (d * d < n);
    return res;
}

int main() {
    freopen("equation.in", "r", stdin);
    freopen("equation.out", "w", stdout);

    int n;
    cin >> n;

    cout << getDivisorCount(n + 1);
}