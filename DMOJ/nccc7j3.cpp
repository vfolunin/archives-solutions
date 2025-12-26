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

    long long n, k;
    cin >> n >> k;

    long long l = 0, r = 1;
    while (r + r / k < n)
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m + m / k >= n)
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
}