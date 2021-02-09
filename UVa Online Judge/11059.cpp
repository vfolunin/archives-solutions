#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    long long maxProd = 0;
    for (int l = 0; l < n; l++) {
        long long prod = 1;
        for (long long r = l; r < n; r++) {
            prod *= a[r];
            maxProd = max(maxProd, prod);
        }
    }

    cout << "Case #" << test << ": The maximum product is " << maxProd << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}