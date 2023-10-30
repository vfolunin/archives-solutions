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

    string a, b;
    cin >> a >> b;

    int aSize = a.size(), bSize = b.size(), res = aSize + bSize;

    for (int from = -aSize + 1; from < bSize; from++) {
        int commonSize = 0;
        bool ok = 1;

        for (int ai = 0, bi = from; ai < aSize && ok; ai++, bi++) {
            if (0 <= bi && bi < bSize) {
                commonSize++;
                ok &= a[ai] != '2' || b[bi] != '2';
            }
        }

        if (ok)
            res = min(res, aSize + bSize - commonSize);
    }

    cout << res;
}