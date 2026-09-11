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

    int frogCount;
    cin >> frogCount;

    set<int> freePos;
    for (int pos = 0; pos < 1.5e6; pos++)
        freePos.insert(pos);

    vector<int> frogPos(frogCount);
    for (int &pos : frogPos) {
        cin >> pos;

        freePos.erase(pos);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;
        index--;

        freePos.insert(frogPos[index]);
        auto it = freePos.upper_bound(frogPos[index]);
        frogPos[index] = *it;
        freePos.erase(it);

        cout << frogPos[index] << "\n";
    }
}