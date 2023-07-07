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
 
    int floorCount;
    cin >> floorCount;

    vector<int> deltas(3);
    for (int &delta : deltas)
        cin >> delta;

    vector<int> can(floorCount);
    can[0] = 1;

    for (int floor = 1; floor < floorCount; floor++)
        for (int delta : deltas)
            can[floor] |= floor >= delta && can[floor - delta];

    cout << count(can.begin(), can.end(), 1);
}