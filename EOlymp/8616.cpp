#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (n < 3)
        return 0;

    if (n % 2)
        cout << (n - 1) * (n - 3) * (2 * n - 1) / 24 << "\n";
    else
        cout << n * (n - 2) * (2 * n - 5) / 24 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}