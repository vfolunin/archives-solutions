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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> side(a.size(), vector<int>(a.size()));
    int res = 0;
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] == '1') {
                side[y][x] = 1 + (y && x ? min({ side[y - 1][x - 1], side[y - 1][x], side[y][x - 1] }) : 0);
                res = max(res, side[y][x]);
            }
        }
    }

    cout << res * res;
}