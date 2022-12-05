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

    vector<int> row(8), col(8), d1(16), d2(16);

    for (int i = 0; i < 8; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        if (row[y] || col[x] || d1[y + x] || d2[y - x + 8]) {
            cout << "YES";
            return 0;
        }

        row[y] = col[x] = d1[y + x] = d2[y - x + 8] = 1;
    }

    cout << "NO";
}