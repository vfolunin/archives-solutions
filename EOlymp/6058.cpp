#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, p;
    cin >> n >> p;

    if (!n)
        return 0;

    int res = pow(n, 1.0 / p);
    if (pow(res + 1, p) - n < n - pow(res, p))
        res++;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}