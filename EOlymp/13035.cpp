#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long size, sum;
    cin >> size >> sum;

    long long halfSize = size / 2;
    long long lSum = (1 + halfSize) * halfSize / 2;
    long long rSum = (size - halfSize + 1 + size) * halfSize / 2;

    cout << (lSum <= sum && sum <= rSum ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}