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

    long long xl, yl, xr, yr;
    cin >> xl >> yl >> xr >> yr;

    long long h = yr - yl;
    long long w = xr - xl;
    long long res = (h / 2 + 1) * (w / 2 + 1);

    if (h && w) {
        h--;
        w--;
        res += (h / 2 + 1) * (w / 2 + 1);
    }

    cout << res;
}