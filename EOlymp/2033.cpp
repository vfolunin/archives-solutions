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

    int res = 1e9;
    for (int k5 = 0; k5 * 5 <= sum; k5++)
        if ((sum - k5 * 5) % 2 == 0)
            res = min(res, k5 + (sum - k5 * 5) / 2);

    cout << res;
}