#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    if (!(cin >> aSize >> bSize))
        return 0;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    vector<int> deltas;
    for (int aValue : a)
        for (int bValue : b)
            if (aValue <= bValue)
                deltas.push_back(bValue - aValue);

    if (deltas.empty()) {
        cout << "0\n";
        return 1;
    }

    sort(deltas.begin(), deltas.end());

    int res = deltas[0], resCount = 1, curCount = 1;
    for (int i = 1; i < deltas.size(); i++) {
        if (deltas[i - 1] == deltas[i])
            curCount++;
        else
            curCount = 1;

        if (resCount < curCount) {
            res = deltas[i];
            resCount = curCount;
        }
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