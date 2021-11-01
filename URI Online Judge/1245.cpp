#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int bootCount;
    if (!(cin >> bootCount))
        return 0;

    map<pair<int, char>, int> unpaired;
    int pairCount = 0;

    for (int i = 0; i < bootCount; i++) {
        int size;
        char type;
        cin >> size >> type;

        char otherType = type == 'D' ? 'E' : 'D';
        if (unpaired[{ size, otherType }]) {
            unpaired[{ size, otherType }]--;
            pairCount++;
        } else {
            unpaired[{ size, type }]++;
        }
    }

    cout << pairCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}