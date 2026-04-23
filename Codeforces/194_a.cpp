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

    int count, targetSum;
    cin >> count >> targetSum;

    int l = -1, r = count + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (2 * m + 3 * (count - m) > targetSum)
            l = m;
        else
            r = m;
    }

    cout << r;
}