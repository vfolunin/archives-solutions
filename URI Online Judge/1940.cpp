#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount, roundCount;
    if (!(cin >> playerCount >> roundCount))
        return 0;

    vector<int> res(playerCount);
    for (int i = 0; i < playerCount * roundCount; i++) {
        int points;
        cin >> points;
        res[i % playerCount] += points;
    }

    cout << res.rend() - max_element(res.rbegin(), res.rend()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}