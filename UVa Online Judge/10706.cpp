#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getBlockLen(long long n) {
    long long res = 0;
    for (long long upperBound = 10, len = 1; 1; upperBound *= 10, len++) {
        if (n < upperBound) {
            res += len * (n - upperBound / 10);
            break;
        } else {
            res += len * (upperBound - upperBound / 10);
        }
    }
    return res;
}

int nthDigit(long long n) {
    if (n < 10)
        return n;
    n -= 10;

    long long len = 2, count = 90;
    while (n >= count * len) {
        n -= count * len;
        len++;
        count *= 10;
    }

    long long number = 1;
    for (int i = 1; i < len; i++)
        number *= 10;
    number += n / len;

    n = len - 1 - n % len;
    for (int i = 0; i < n; i++)
        number /= 10;

    return number % 10;
}

void solve() {
    long long n;
    cin >> n;

    long long blockNumber = 1;
    while (1) {
        int blockLen = getBlockLen(blockNumber);
        if (n <= blockLen)
            break;
        n -= blockLen;
        blockNumber++;
    }

    cout << nthDigit(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}