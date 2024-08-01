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

    int l = 1, r, target;
    cin >> r >> target;

    int res = 0;
    while (1) {
        int m = l + (r - l) / 2;
        res++;
        if (m == target)
            break;
        else if (m < target)
            l = m + 1;
        else
            r = m - 1;
    }

    cout << res;
}