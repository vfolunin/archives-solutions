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

    long long n, a, b;
    cin >> n >> a >> b;
    n--;

    long long l = -1, r = n * a;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m / a + m / b < n)
            l = m;
        else
            r = m;
    }

    cout << min(a, b) + r;
}