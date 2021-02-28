#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    unordered_set<int> s(a.begin(), a.end());
    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        s.erase(a[i]);
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            s.erase(a[j]);
            for (int k = 0; k < n; k++) {
                if (i == k || j == k)
                    continue;
                s.erase(a[k]);
                if (s.count(a[i] - a[j] - a[k])) {
                    cout << a[i] << "\n";
                    return 1;
                }
                s.insert(a[k]);
            }
            s.insert(a[j]);
        }
        s.insert(a[i]);
    }

    cout << "no solution\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}