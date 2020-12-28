#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long r = sqrt(n);
    cout << (r * r == n ? "yes\n" : "no\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}