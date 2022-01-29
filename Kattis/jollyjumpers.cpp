#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    unordered_set<int> diffs;
    for (int i = 1; i < n; i++) {
        int diff = abs(a[i] - a[i - 1]);
        if (1 <= diff && diff <= n - 1)
            diffs.insert(diff);
    }

    cout << (diffs.size() == n - 1 ? "Jolly\n" : "Not jolly\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}