#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
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

    int a = 2;
    while (!isPrime(a) || !isPrime(n - a))
        a++;

    cout << n << " = " << a << " + " << n - a << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}