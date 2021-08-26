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

    vector<int> a(size), posInA(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        a[i]--;
        posInA[a[i]] = i;
    }

    vector<int> b(size);
    for (int &x : b) {
        cin >> x;
        x--;
    }

    int res = 0;

    for (int l = 0; l < size; l++) {
        int pl = posInA[b[l]], pr = pl;
        for (int r = l + 1; r < size; r++) {
            pl = min(pl, posInA[b[r]]);
            pr = max(pr, posInA[b[r]]);
            res += pr - pl == r - l;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}