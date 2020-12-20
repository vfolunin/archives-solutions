#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

void solve(int n) {
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
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}