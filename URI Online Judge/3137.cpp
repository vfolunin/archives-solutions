#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int l = 1, r = 9, d = 1, res = 0;
    while (l <= n) {
        res += (min(n, r) - l + 1) * d;
        l *= 10;
        r = r * 10 + 9;
        d++;
    }

    cout << res << "\n";
}