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

    long long radius;
    cin >> radius;

    long long res = 0;
    for (long long y = -radius; y <= radius; y++) {
        int x = sqrt(radius * radius - y * y) + 1e-9;
        res += 2 * x + 1;
    }

    cout << res;
}