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

    int sum;
    cin >> sum;

    long long res = 0;
    for (int a = 0; a < 1e4 && a <= sum; a++) {
        for (int b = 0; b < 1e3 && a + b <= sum; b++) {
            int cur = sum - a - b;
            if (cur <= 999 * 2)
                res += min(cur, 999) - max(cur - 999, 0) + 1;
        }
    }

    cout << res;
}