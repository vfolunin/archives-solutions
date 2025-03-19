#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int divisorCount = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisorCount++;
            divisorCount += d * d != n;
        }
    }
    return divisorCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 1, resCount = 1;
    for (int i = 2; i <= n; i++) {
        int count = getDivisorCount(i);
        if (resCount <= count) {
            resCount = count;
            res = i;
        }
    }

    cout << res << "\n" << resCount;
}