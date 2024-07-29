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

    int floorCount, targetFloor, floorDelta;
    cin >> floorCount >> targetFloor >> floorDelta;

    int res = 1e9;
    for (int floor = 1; floor <= floorCount; floor += floorDelta) {
        if (floor <= targetFloor)
            res = min(res, (targetFloor - floor) * 200);
        else
            res = min(res, (floor - targetFloor) * 100);
    }

    cout << res;
}