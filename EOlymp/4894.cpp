#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;

    cout << ones(n - 1) % 3 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}