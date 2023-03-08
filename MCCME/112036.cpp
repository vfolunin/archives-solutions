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

    vector<long long> a(4);
    for (long long &value : a)
        cin >> value;

    long long squareCount = min(a[0], a[1]) + min(a[2], a[3]);

    long long l = 0, r = 1;
    while (r * r <= squareCount)
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * m <= squareCount)
            l = m;
        else
            r = m;
    }

    cout << l;
}