#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    return n > 1 ? n * factorial(n - 1) : 1;
}

bool solve() {
    int n, k;
    if (!(cin >> n >> k))
        return 0;

    long long res = factorial(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        res /= factorial(x);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}