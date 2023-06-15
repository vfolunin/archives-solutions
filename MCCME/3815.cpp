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

    int targetFloorCount;
    cin >> targetFloorCount;

    vector<int> tossCount(targetFloorCount + 1, 1e9);
    tossCount[0] = tossCount[1] = 0;

    for (int floorCount = 2; floorCount <= targetFloorCount; floorCount++)
        for (int tossFloor = 1; tossFloor <= floorCount; tossFloor++)
            tossCount[floorCount] = min(tossCount[floorCount], 1 + max(tossCount[tossFloor - 1], floorCount - tossFloor));

    cout << tossCount[targetFloorCount];
}