#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int l = n, r = n;
    while (!isPrime(l))
        l--;
    while (!isPrime(r))
        r++;

    cout << r - l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}