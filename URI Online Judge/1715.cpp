#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount, matchCount;
    if (!(cin >> playerCount >> matchCount))
        return 0;

    int res = 0;
    for (int i = 0; i < playerCount; i++) {
        int ok = 1;
        for (int j = 0; j < matchCount; j++) {
            int goals;
            cin >> goals;
            ok &= (bool)goals;
        }
        res += ok;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}