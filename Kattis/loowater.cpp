#include <iostream>
#include <iomanip>
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

    multiset<int> heads;
    for (int i = 0; i < headCount; i++) {
        int time;
        cin >> time;
        heads.insert(time);
    }

    multiset<int> knights;
    for (int i = 0; i < knightCount; i++) {
        int time;
        cin >> time;
        knights.insert(time);
    }

    int totalCost = 0;

    for (int head : heads) {
        auto it = knights.lower_bound(head);

        if (it == knights.end()) {
            cout << "Loowater is doomed!\n";
            return 1;
        }
        
        totalCost += *it;
        knights.erase(it);
    }

    cout << totalCost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}