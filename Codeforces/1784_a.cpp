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

    sort(a.begin(), a.end());

    long long res = a[0] - 1;
    a[0] = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] + 1 < a[i]) {
            res += a[i] - a[i - 1] - 1;
            a[i] = a[i - 1] + 1;
        }
    }

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