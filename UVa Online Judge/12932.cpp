#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    vector<int> row(h), col(w);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }

    int r = max_element(row.begin(), row.end()) - row.begin();
    int c = max_element(col.begin(), col.end()) - col.begin();

    cout << "Case " << test << ": ";

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (row[r] + col[c] - a[r][c] < row[i] + col[j] - a[i][j]) {
                cout << "Weak\n";
                return 1;
            }
        }
    }

    cout << "Strong\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}