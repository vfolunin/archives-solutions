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

    int l, r, rem, mod;
    cin >> l >> r >> rem >> mod;

    if (l > r)
        swap(l, r);

    if (l % mod <= rem)
        l += rem - l % mod;
    else
        l = (l + mod - 1) / mod * mod + rem;

    for (; l <= r; l += mod)
        cout << l << " ";
}