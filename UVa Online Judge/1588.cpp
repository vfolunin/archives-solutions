#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    int res = a.size() + b.size();

    for (int fromA = 0; fromA < a.size(); fromA++) {
        bool ok = 1;
        int common = 0;
        for (int ai = fromA, bi = 0; ok && ai < a.size() && bi < b.size(); ai++, bi++) {
            ok &= a[ai] != '2' || b[bi] != '2';
            common++;
        }
        if (ok)
            res = min<int>(res, a.size() + b.size() - common);
    }

    for (int fromB = 0; fromB < b.size(); fromB++) {
        bool ok = 1;
        int common = 0;
        for (int ai = 0, bi = fromB; ok && ai < a.size() && bi < b.size(); ai++, bi++) {
            ok &= a[ai] != '2' || b[bi] != '2';
            common++;
        }
        if (ok)
            res = min<int>(res, a.size() + b.size() - common);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}