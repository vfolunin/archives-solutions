#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int treeCount, height, delta;
    cin >> treeCount >> height >> delta;

    vector<vector<int>> acorns(treeCount, vector<int>(height + 1));
    for (int i = 0; i < treeCount; i++) {
        int acornCount;
        cin >> acornCount;

        for (int j = 0; j < acornCount; j++) {
            int h;
            cin >> h;

            acorns[i][h]++;
        }
    }

    vector<int> acornsRow(height + 1);
    for (int h = height; h >= 0; h--) {
        for (int i = 0; i < treeCount; i++) {
            int add = 0;

            if (h < height)
                add = acorns[i][h + 1];

            if (h + delta <= height)
                add = max(add, acornsRow[h + delta]);

            acorns[i][h] += add;
            acornsRow[h] = max(acornsRow[h], acorns[i][h]);
        }
    }

    cout << acornsRow[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}