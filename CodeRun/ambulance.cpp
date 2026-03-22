#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int flat1, floorCount, flat2, entrance2, floor2;
    cin >> flat1 >> floorCount >> flat2 >> entrance2 >> floor2;
    flat1--;
    flat2--;
    entrance2--;
    floor2--;

    unordered_set<int> entrances, floors;
    for (int flatPerFloor = 1; flatPerFloor <= 1000; flatPerFloor++) {
        int flatPerEntrance = flatPerFloor * floorCount;
        if (flat2 / flatPerEntrance == entrance2 && flat2 % flatPerEntrance / flatPerFloor == floor2) {
            entrances.insert(flat1 / flatPerEntrance);
            floors.insert(flat1 % flatPerEntrance / flatPerFloor);
        }
    }

    if (entrances.empty() || floors.empty())
        cout << "-1 -1";
    else
        cout << (entrances.size() > 1 ? 0 : *entrances.begin() + 1) << " " << (floors.size() > 1 ? 0 : *floors.begin() + 1);
}