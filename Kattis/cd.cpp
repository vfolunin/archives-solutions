#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    set<int> a;
    for (int i = 0; i < aSize; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    int res = 0;
    for (int i = 0; i < bSize; i++) {
        int x;
        cin >> x;
        res += a.count(x);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}