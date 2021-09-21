#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, updateCount;
    cin >> size >> updateCount;

    vector<int> p(size + 1);

    for (int i = 0; i < updateCount; i++) {
        int l, r, add;
        cin >> l >> r >> add;
        p[l] += add;
        p[r + 1] -= add;
    }

    for (int i = 1; i < p.size(); i++)
        p[i] += p[i - 1];

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;
        cout << p[index] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}