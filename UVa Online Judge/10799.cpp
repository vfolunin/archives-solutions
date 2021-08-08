#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long l, r, k;
    cin >> l >> r >> k;

    if (!l && !r && !k)
        return 0;

    long long width = r - l + 1;
    long long res = 0;

    if (k % 2) {
        for (long long segmentWidth = k; segmentWidth <= width; segmentWidth += k - 1)
            res += width - segmentWidth + 1;
    } else {
        for (long long segmentWidth = 2 * k - 1; segmentWidth <= width; segmentWidth += 2 * (k - 1))
            res += width - segmentWidth + 1;
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}