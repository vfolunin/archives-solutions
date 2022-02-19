#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> row(8), col(8), d1(15), d2(15);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char c;
            cin >> c;

            if (c == '*') {
                if (row[y] || col[x] || d1[y + x] || d2[y - x + 7]) {
                    cout << "invalid";
                    return 0;
                }
                row[y] = col[x] = d1[y + x] = d2[y - x + 7] = 1;
            }
        }
    }

    cout << (find(row.begin(), row.end(), 0) == row.end() ? "valid" : "invalid");
}