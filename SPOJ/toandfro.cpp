#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int colCount;
    string s;
    if (!(cin >> colCount >> s))
        return 0;

    int rowCount = s.size() / colCount;

    string res(s.size(), ' ');
    for (int i = 0; i < s.size(); i++) {
        int x = i / colCount, y = i % colCount;
        if (x % 2)
            y = colCount - 1 - y;
        res[y * rowCount + x] = s[i];
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}