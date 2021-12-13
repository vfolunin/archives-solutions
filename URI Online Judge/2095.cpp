#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int soldierCount;
    cin >> soldierCount;

    multiset<int> armyA;
    for (int i = 0; i < soldierCount; i++) {
        int skill;
        cin >> skill;
        armyA.insert(skill);
    }

    multiset<int> armyB;
    for (int i = 0; i < soldierCount; i++) {
        int skill;
        cin >> skill;
        armyB.insert(skill);
    }

    int winCount = 0;
    for (int skill : armyB) {
        auto it = armyA.lower_bound(skill);
        if (it != armyA.begin()) {
            winCount++;
            armyA.erase(--it);
        }
    }

    cout << winCount << "\n";
}