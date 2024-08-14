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

    long long l, r;
    cin >> l >> r;

    long long res = 0;

    if (l + 10 >= r) {
        for (long long i = l; i <= r; i++)
            res ^= i;
    } else {
        if (l % 2)
            res ^= l++;
        if (r % 2 == 0)
            res ^= r--;
        if ((r - l + 1) / 2 % 2)
            res ^= 1;
    }

    cout << res;
}