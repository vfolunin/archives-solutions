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

    int index;
    cin >> index;
    index--;

    int floor = 0, room = 0, side = 1;
    for ( ; index >= side * side; side++) {
        index -= side * side;
        floor += side;
    }

    floor += index / side;
    room = index % side;

    cout << floor + 1 << " " << room + 1;
}