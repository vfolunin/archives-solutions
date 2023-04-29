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

    int n, base;
    cin >> n >> base;

    int res = n;
    for (int d = 2; d <= base; d++) {
        if (base % d)
            continue;

        int num = 0;
        for (long long dPower = d; dPower <= n; dPower *= d)
            num += n / dPower;

        int den = 0;
        while (base % d == 0) {
            base /= d;
            den++;
        }

        res = min(res, num / den);
    }

    cout << res;
}