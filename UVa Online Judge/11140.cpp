#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool fits(vector<string> &a, vector<string> &b, int fromY, int fromX) {
    for (int y = 0; y < b.size(); y++) {
        for (int x = 0; x < b[y].size(); x++) {
            if (b[y][x] == '.')
                continue;
            int ay = fromY + y, ax = fromX + x;
            if (ay < 0 || ay >= a.size() || ax < 0 || ax >= a[ay].size() || a[ay][ax] == '.')
                return 0;
        }
    }
    return 1;
}

bool fits(vector<string> &a, vector<string> &b) {
    for (int y = 1 - (int)b.size(); y < (int)a.size(); y++)
        for (int x = 1 - (int)b[0].size(); x < (int)a[0].size(); x++)
            if (fits(a, b, y, x))
                return 1;
    return 0;
}

void solve() {
    int ah, aw, pieceCount;
    cin >> ah >> aw >> pieceCount;

    vector<string> a(ah);
    for (string &row : a)
        cin >> row;

    for (int i = 0; i < pieceCount; i++) {
        int bh, bw;
        cin >> bh >> bw;

        vector<string> b(bh);
        for (string &row : b)
            cin >> row;

        cout << (fits(a, b) ? "Yes\n" : "No\n");
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}