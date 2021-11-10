#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w) || !h && !w)
        return 0;

    int res = 0, prev = 0, cur = h;
    for (int i = 0; i < w; i++) {
        prev = cur;
        cin >> cur;
        if (cur < prev)
            res += prev - cur;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}