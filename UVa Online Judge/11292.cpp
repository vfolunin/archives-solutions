#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int headCount, knightCount;
    cin >> headCount >> knightCount;

    if (!headCount && !knightCount)
        return 0;

    vector<int> heads(headCount);
    for (int &x : heads)
        cin >> x;

    multiset<int> knights;
    for (int i = 0; i < knightCount; i++) {
        int x;
        cin >> x;
        knights.insert(x);
    }

    int cost = 0;
    for (int x : heads) {
        auto it = knights.lower_bound(x);
        if (it == knights.end()) {
            cout << "Loowater is doomed!\n";
            return 1;
        }
        cost += *it;
        knights.erase(it);
    }
    cout << cost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}