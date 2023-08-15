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

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "ADD") {
            int y, x;
            cin >> y >> x;
            y--;
            x--;

            a[y][x] = 1;
        } else if (type == "LISTSETSOF") {
            int y;
            cin >> y;
            y--;

            bool found = 0;
            for (int x = 0; x < w; x++) {
                if (a[y][x]) {
                    cout << x + 1 << " ";
                    found = 1;
                }
            }
            if (!found)
                cout << -1;
            cout << "\n";
        } else {
            int x;
            cin >> x;
            x--;

            bool found = 0;
            for (int y = 0; y < h; y++) {
                if (a[y][x]) {
                    cout << y + 1 << " ";
                    found = 1;
                }
            }
            if (!found)
                cout << -1;
            cout << "\n";
        }
    }
}