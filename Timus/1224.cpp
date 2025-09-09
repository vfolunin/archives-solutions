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

    long long h, w;
    cin >> h >> w;

    long long size = h < w ? h : w, res = 0;
    if (size % 2) {
        if (size > 2)
            res += 2 * (size - 1);
        if (size != h)
            res++;
    } else {
        if (size > 2)
            res += 2 * (size - 2);
        if (size != h)
            res += 3;
        else
            res += 2;
    }

    cout << res;
}