#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getArea(vector<string> &a) {
    int res = 0;

    for (int y01 = 1; y01 + 1 < a[0].size(); y01++) {
        for (int x01 = 1; x01 + 1 < a[1].size(); x01++) {
            if (a[0][y01] != a[1][x01])
                continue;

            for (int y02 = y01 + 2; y02 + 1 < a[0].size(); y02++) {
                for (int x02 = 1; x02 + 1 < a[1].size(); x02++) {
                    if (a[0][y02] != a[2][x02])
                        continue;

                    for (int x13 = x01 + 2; x13 + 1 < a[1].size() && x13 + x02 - x01 + 1 < a[2].size(); x13++) {
                        for (int y13 = 1; y13 + 1 < a[3].size() && y13 + y02 - y01 + 1 < a[3].size(); y13++) {
                            if (a[1][x13] != a[3][y13] || a[2][x13 + x02 - x01] != a[3][y13 + y02 - y01])
                                continue;

                            if (res < (y02 - y01 - 1) * (x13 - x01 - 1))
                                cout << "";

                            res = max(res, (y02 - y01 - 1) * (x13 - x01 - 1));
                        }
                    }
                }
            }
        }
    }

    return res;
}

bool solve() {
    vector<string> a(4);
    if (!(cin >> a[0] >> a[1] >> a[2] >> a[3]))
        return 0;

    int res = 0;
    sort(a.begin(), a.end());
    do {
        res = max(res, getArea(a));
    } while (next_permutation(a.begin(), a.end()));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}