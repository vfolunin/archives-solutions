#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int an, bn;
    cin >> an >> bn;

    if (!an && !bn)
        return 0;

    map<int, int> count;
    int res = 0;

    for (int i = 0; i < an; i++) {
        int x;
        cin >> x;

        res += x;
        count[x]++;
    }

    for (int i = 0; i < bn; i++) {
        int x;
        cin >> x;

        if (!count[x])
            res += x;
        else
            count[x]--;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}