#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    unordered_set<int> sums;

    for (int y = 0; y < a.size(); y++) {
        int sum = 0;
        for (int x = 0; x < a.size(); x++)
            sum += a[y][x];
        sums.insert(sum);
    }

    for (int x = 0; x < a.size(); x++) {
        int sum = 0;
        for (int y = 0; y < a.size(); y++)
            sum += a[y][x];
        sums.insert(sum);
    }

    cout << (sums.size() == 1 ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}