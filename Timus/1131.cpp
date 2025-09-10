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

    long long totalCount, patchLimit;
    cin >> totalCount >> patchLimit;

    long long patchedCount = 1;
    int res = 0;
    while (patchedCount < totalCount && patchedCount < patchLimit) {
        patchedCount *= 2;
        res++;
    }
    res += (totalCount - patchedCount + patchLimit - 1) / patchLimit;

    cout << res;
}