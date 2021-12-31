#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    size *= 2;
    vector<int> a(size);
    for (int &x : a) {
        cin >> x;
        x = x % 2 == 0;
    }

    vector<vector<pair<int, int>>> win(size, vector<pair<int, int>>(size));
    for (int i = 0; i < size; i++)
        win[i][i] = { a[i], 0 };
    for (int len = 2; len <= size; len++) {
        for (int l = 0, r = len - 1; r < size; l++, r++) {
            if (a[l] + win[l + 1][r].second >= a[r] + win[l][r - 1].second)
                win[l][r] = { a[l] + win[l + 1][r].second, win[l + 1][r].first };
            else
                win[l][r] = { a[r] + win[l][r - 1].second, win[l][r - 1].first };
        }
    }

    cout << win[0][size - 1].first << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}