#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(vector<vector<int>> &a, int sign) {
    int res = 0;
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            res += a[y][x] == sign;
    return res;
}

bool wins(vector<vector<int>> &a, int sign) {
    bool d1 = 1, d2 = 1;
    for (int y = 0; y < a.size(); y++) {
        d1 &= a[y][y] == sign;
        d2 &= a[y][a.size() - 1 - y] == sign;

        bool row = 1, col = 1;
        for (int x = 0; x < a.size(); x++) {
            row &= a[y][x] == sign;
            col &= a[x][y] == sign;
        }
        if (row || col)
            return 1;
    }
    return d1 || d2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a(3, vector<int>(3));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    int k1 = count(a, 1);
    int k2 = count(a, 2);

    if (k1 == k2 + 1)
        cout << (wins(a, 2) ? "NO" : "YES");
    else if (k1 == k2)
        cout << (wins(a, 1) ? "NO" : "YES");
    else
        cout << "NO";
}