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

    l += abs(l) % 2;
    r -= abs(r) % 2;

    if (l > r) {
        cout << 0;
        return 0;
    }

    l /= 2;
    r /= 2;

    cout << (l + r) * (r - l + 1);
}