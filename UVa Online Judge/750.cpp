#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int col, vector<int> &placement, set<pair<int, int>> &used, int &ans) {
    if (col == 8) {
        cout << setw(2) << ans++ << "     ";
        for (int p : placement)
            cout << setw(2) << p + 1;
        cout << "\n";
        return;
    }
    if (used.count({ 1, col })) {
        rec(col + 1, placement, used, ans);
        return;
    }

    for (int row = 0; row < 8; row++) {
        if (used.count({ 0, row }))
            continue;
        if (used.count({ 2, row + col }))
            continue;
        if (used.count({ 3, row - col }))
            continue;

        used.insert({ 0, row });
        used.insert({ 2, row + col });
        used.insert({ 3, row - col });

        placement[col] = row;
        rec(col + 1, placement, used, ans);

        used.erase({ 0, row });
        used.erase({ 2, row + col });
        used.erase({ 3, row - col });
    }
}

void solve(int test) {
    int row, col;
    cin >> row >> col;
    row--;
    col--;

    vector<int> placement(8, -1);
    placement[col] = row;
    set<pair<int, int>> used = { {0, row}, {1, col}, {2, row + col}, {3, row - col} };
    int ans = 1;
    
    if (test)
        cout << "\n";
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n";
    cout << "\n";
    rec(0, placement, used, ans);    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}