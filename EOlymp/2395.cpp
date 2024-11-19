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

    long long res = 0;
    for (long long value = 1; value <= r; value *= 2)
        if (l <= value)
            res += value;

    cout << res;
}