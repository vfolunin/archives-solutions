#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &a, int row, set<int> &cols, set<int> &diags1, set<int> &diags2, int sum, int &maxSum) {
    if (row == 8) {
        maxSum = max(maxSum, sum);
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (cols.count(col) || diags1.count(row + col) || diags2.count(row - col))
            continue;
        cols.insert(col);
        diags1.insert(row + col);
        diags2.insert(row - col);
        rec(a, row + 1, cols, diags1, diags2, sum + a[row][col], maxSum);
        cols.erase(col);
        diags1.erase(row + col);
        diags2.erase(row - col);
    }
}

void solve() {
    vector<vector<int>> a(8, vector<int>(8));
    for (auto &row : a)
        for (int &x : row)
            cin >> x;

    set<int> cols, diags1, diags2;
    int maxSum = 0;
    rec(a, 0, cols, diags1, diags2, 0, maxSum);

    cout << setw(5) << maxSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}