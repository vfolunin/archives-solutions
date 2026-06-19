#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = abs(a[0] - a[1]), maxDelta = max(abs(a[0] - a[1]), abs(a[a.size() - 2] - a[a.size() - 1]));
    for (int i = 1; i + 1 < a.size(); i++) {
        res += abs(a[i] - a[i + 1]);
        maxDelta = max(maxDelta, abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
    }
    res -= maxDelta;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}