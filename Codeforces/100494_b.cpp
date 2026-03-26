#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n, bits;
    if (!(cin >> n >> bits))
        return 0;

    cout << (n >= (1LL << (bits + 1)) ? "no\n" : "yes\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}