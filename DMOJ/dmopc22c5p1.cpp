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

    int n;
    cin >> n;

    long long res = 0;
    for (int count2 = 0; count2 * 2 <= n; count2++) {
        int count1 = n - count2 * 2;
        res = max(res, count1 * (count1 - 1LL) / 2 * count2);
    }

    cout << res;
}