#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long n;
    cin >> n;

    long long res = 1;
    for (long long d = 2; d * d <= n; d++) {
        int power = 0;
        while (n % d == 0) {
            n /= d;
            res *= d;
            power++;
        }
        if (power % 2)
            res *= d;
    }
    if (n > 1)
        res *= n * n;

    cout << "Caso #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}