#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 0;
    for (long long x = 1; x * x < n; x++) {
        long long y = sqrt(n - x * x);
        y -= x * x + y * y == n;
        res += y;
    }

    cout << res;
}