#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, targetId;
    if (!(cin >> n >> targetId))
        return 0;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int id, type;
        cin >> id >> type;
        res += id == targetId && !type;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}