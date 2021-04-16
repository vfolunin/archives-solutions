#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long pow(long long x, int p) {
    long long res = 1;
    for (int i = 0; i < p; i++)
        res *= x;
    return res;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    cout << (pow(n, 6) + 3 * pow(n, 4) + 12 * pow(n, 3) + 8 * n * n) / 24 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}