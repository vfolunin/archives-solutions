#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readGrid() {
    vector<string> grid(5, string(6, ' '));
    for (int j = 0; j < 6; j++)
        for (int i = 0; i < 5; i++)
            cin >> grid[i][j];

    for (string &row : grid) {
        sort(row.begin(), row.end());
        row.erase(unique(row.begin(), row.end()), row.end());
    }

    return grid;
}

vector<string> combineGrids(const vector<string> &a, const vector<string> &b) {
    vector<string> grid(5);
    for (int i = 0; i < 5; i++)
        set_intersection(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), back_inserter(grid[i]));
    return grid;
}

void solve() {
    int index;
    cin >> index;
    index--;

    vector<string> grid = combineGrids(readGrid(), readGrid());

    int count = 1;
    for (int i = 0; i < 5; i++)
        count *= grid[i].size();

    if (!count) {
        cout << "NO\n";
        return;
    }

    string password;
    for (int i = 0; i < 5; i++) {
        count /= grid[i].size();

        int letter = index / count;
        if (letter >= grid[i].size()) {
            cout << "NO\n";
            return;
        }

        password += grid[i][letter];
        index %= count;
    }

    cout << password << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}