#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    int occupiedCount;
    cin >> occupiedCount;

    vector<set<int>> occupied(h, { -1, w + 1 });
    for (int i = 0; i < occupiedCount; i++) {
        char row, sign;
        int col;
        cin >> row >> col >> sign;
        row -= 'A';
        col -= sign == '-';
        occupied[row].insert(col);
    }

    int friendCount;
    cin >> friendCount;

    bool ok = 1;
    for (int i = 0; i < friendCount; i++) {
        char row;
        int col;
        cin >> row >> col;
        row -= 'A';

        auto r = occupied[row].lower_bound(col);
        auto l = prev(r);
        if (*l + 1 == *r)
            ok = 0;
        else
            occupied[row].insert(*l + 1);
    }

    cout << (ok ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}