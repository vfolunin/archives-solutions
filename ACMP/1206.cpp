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

    long long areaL, areaR, perimeterL, perimeterR;
    cin >> areaL >> areaR >> perimeterL >> perimeterR;

    long long res = 0;
    for (long long h = 1; h * h <= areaR; h++) {
        long long wl = max({ h, (areaL + h - 1) / h, (perimeterL - 2 * h + 1) / 2 });
        long long wr = min(areaR / h, (perimeterR - 2 * h) / 2);
        if (wl <= wr)
            res += wr - wl + 1;
    }

    cout << res;
}