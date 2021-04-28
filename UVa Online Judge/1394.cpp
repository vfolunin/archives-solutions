#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int joseph(int n, int k) {
    return n > 1 ? (joseph(n - 1, k) + k) % n : 0;
}

bool solve() {
    int n, k, m;
    cin >> n >> k >> m;

    if (!n)
        return 0;

    int shift = ((n - k + m) % n + n) % n;
    int res = (joseph(n, k) + shift) % n + 1;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}