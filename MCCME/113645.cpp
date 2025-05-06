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

    int hLimit, wLimit, area;
    cin >> hLimit >> wLimit >> area;

    long long res = 0;

    for (int h = 1; h * h <= area; h++) {
        if (area % h)
            continue;
        int w = area / h;

        if (h <= hLimit && w <= wLimit)
            res += (hLimit - h + 1LL) * (wLimit - w + 1);
        if (h != w && h <= wLimit && w <= hLimit)
            res += (wLimit - h + 1LL) * (hLimit - w + 1);
    }

    cout << res;
}