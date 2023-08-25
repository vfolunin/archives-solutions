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

    if (l > r)
        swap(l, r);

    l = (l + 1) / 2;
    r = (r + 1) / 2;

    cout << max(0LL, r - l - 1);
}