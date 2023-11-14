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

    int flatCount, entranceCount, floorCount, flatNumber;
    cin >> flatCount >> entranceCount >> floorCount >> flatNumber;

    int flatsPerEntrance = flatCount / entranceCount;
    cout << (flatNumber - 1) / flatsPerEntrance + 1 << " ";

    int flatsPerFloor = flatsPerEntrance / floorCount;
    cout << (flatNumber - 1) % flatsPerEntrance / flatsPerFloor + 1;
}