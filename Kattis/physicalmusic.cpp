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

    set<int> res;

    for (int i = a.size() - 1, suffixMin = size; i >= 0; i--) {
        if (suffixMin < a[i])
            res.insert(a[i]);
        suffixMin = min(suffixMin, a[i]);
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}