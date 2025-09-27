#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int peopleCount;
    cin >> peopleCount;

    if (!peopleCount)
        return 0;

    int activeTime = 0, l = -1e9, r = -1e9;
    for (int i = 0; i < peopleCount; i++) {
        cin >> l;
        activeTime += 10 - max(0, r - l);
        r = l + 10;
    }

    cout << activeTime << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}