#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    int processCount;
    if (!(cin >> s >> processCount))
        return 0;

    int res = 0, rRow = 0;
    for (char c : s) {
        if (c == 'R') {
            rRow++;
        } else {
            res += (rRow + processCount - 1) / processCount + 1;
            rRow = 0;
        }
    }
    res += (rRow + processCount - 1) / processCount;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}