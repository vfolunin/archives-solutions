#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int floorCount, peoplePerRoom;
    cin >> floorCount >> peoplePerRoom;

    cout << floorCount * (floorCount + 1) * (2 * floorCount + 1) / 6 * peoplePerRoom << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}