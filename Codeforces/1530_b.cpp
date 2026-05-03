#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int height, width;
    cin >> height >> width;

    vector<string> res(height, string(width, '0'));
    for (int l = 0, r = width - 1; l <= r; l += 2, r -= 2) {
        res[0][l] = res[height - 1][l] = '1';
        if (l + 1 < r)
            res[0][r] = res[height - 1][r] = '1';
    }
    for (int l = 0, r = height - 1; l <= r; l += 2, r -= 2) {
        res[l][0] = res[l][width - 1] = '1';
        if (l + 1 < r)
            res[r][0] = res[r][width - 1] = '1';
    }

    for (string &row : res)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}