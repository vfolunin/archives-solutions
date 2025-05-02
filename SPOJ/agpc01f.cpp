#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];

        if (i)
            a[i] = min(a[i], a[i - 1]);
    }

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        cout << a[index - 1] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}