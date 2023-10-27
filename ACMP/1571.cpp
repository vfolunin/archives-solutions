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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<long long>> table(h, vector<long long>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> table[y][x];

            if (y && table[y][x] <= table[y - 1][x] || x && table[y][x] <= table[y][x - 1]) {
                cout << "false";
                return 0;
            }
        }
    }

    long long a = table[0][0], b = 1;
    if (h > 1 && w > 1) {
        a = table[0][1] - table[0][0];
        b = table[1][0] - table[0][0];
    } else if (h == 1 && w > 1) {
        a = table[0][1] - table[0][0];
        b = table[0][0] / a;
    } else if (h > 1 && w == 1) {
        b = table[1][0] - table[0][0];
        a = table[0][0] / b;
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (table[y][x] != (a + y) * (b + x)) {
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";
}