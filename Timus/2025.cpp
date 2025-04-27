#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long num, den;
    cin >> num >> den;

    long long smallSize = num / den, smallCount = den - num % den;
    long long bigSize = (num + den - 1) / den, bigCount = num % den;

    cout << smallCount * (smallCount - 1) / 2 * smallSize * smallSize +
            smallCount * bigCount * smallSize * bigSize +
            bigCount * (bigCount - 1) / 2 * bigSize * bigSize << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}