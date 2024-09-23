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

    int h, w, testCount;
    cin >> h >> w >> testCount;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<pair<int, char>> tests(testCount);
    for (auto &[i, c] : tests)
        cin >> i >> c;

    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        bool ok = 1;
        for (auto &[j, c] : tests)
            ok &= a[i][j - 1] == c;

        if (ok)
            res.push_back(i);
    }

    if (res.size() == 1)
        cout << "unique\n" << res[0] + 1;
    else
        cout << "ambiguous\n" << res.size();
}