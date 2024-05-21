#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    unordered_map<int, int> count;
    int maxKey, maxCount = 0;

    for (int i = l; i <= r; i++) {
        int key = getDivisorCount(i);
        if (maxCount < ++count[key]) {
            maxKey = key;
            maxCount = count[key];
        }
    }

    cout << maxKey << " " << maxCount;
}