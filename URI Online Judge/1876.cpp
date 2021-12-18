#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int prevPos = -1, res = 0;
    for (int pos = 0; pos < s.size(); pos++) {
        if (s[pos] == 'x') {
            if (prevPos == -1)
                res = max(res, pos);
            else
                res = max(res, (pos - prevPos - 1) / 2);
            prevPos = pos;
        }
    }
    res = max(res, (int)s.size() - prevPos - 1);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}