#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int reverse(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return n >= 2;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (!isPrime(n))
        cout << n << " is not prime.\n";
    else if (int r = reverse(n); r != n && isPrime(r))
        cout << n << " is emirp.\n";
    else
        cout << n << " is prime.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}