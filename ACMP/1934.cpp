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

    if (size == 1) {
        cout << (sum == 1 ? "YES\n" : "NO\n");
    } else {
        long long maxSum = (size - 1) * (size + 2) / 2 - 1;
        cout << (abs(sum) <= abs(maxSum) && (sum - maxSum) % 2 == 0 ? "YES\n" : "NO\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}