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

    for (int l = 0; l < a.size(); l++) {
        int sum1 = 0, sum2 = 0;
        for (int r = l; r < a.size(); r++) {
            sum1 += a[r][r];
            sum2 += a[r][a.size() - 1 - r];
            if (sums.contains(sum1) || sums.contains(sum2)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}