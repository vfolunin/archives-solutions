#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long n;
    if (!(cin >> n))
        return 0;

    cout << "Case " << test << ": ";
    if (n == 1) {
        cout << "Impossible\n";
        return 1;
    }
    
    for (long long num = 2; num * (num - 1) <= n; num++) {
        long long quot = num;
        for (long long den = num - 1; quot < n && den > 1; den--) {
            quot *= den;
            if (quot == n) {
                cout << num << " " << den - 1 << "\n";
                return 1;
            }
        }
    }
    cout << n << " " << n - 1 << "\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}