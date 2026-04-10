#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, size;
    cin >> n >> size;

    vector<int> a(size);
    bool nonIncreasing = 0;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        nonIncreasing |= i && a[i - 1] >= a[i];
    }

    cout << (nonIncreasing ? 1 : n - a.back() + 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}