#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int floorCount, capacity, peopleCount;
    cin >> floorCount >> capacity >> peopleCount;

    vector<int> targetFloor(peopleCount);
    for (int &f : targetFloor)
        cin >> f;
    sort(targetFloor.rbegin(), targetFloor.rend());

    int res = 0;
    for (int i = 0; i < peopleCount; i += capacity)
        res += targetFloor[i] * 2;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}