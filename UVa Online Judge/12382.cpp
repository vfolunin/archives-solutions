#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<int> rowCount(h);
    int res = 0;
    for (int row = 0; row < h; row++) {
        cin >> rowCount[row];
        res += rowCount[row];
    }

    for (int col = 0; col < w; col++) {
        int colCount;
        cin >> colCount;

        sort(rowCount.rbegin(), rowCount.rend());

        for (int row = 0; row < h; row++) {
            if (rowCount[row] && colCount) {
                rowCount[row]--;
                colCount--;
            }
        }

        res += colCount;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}