#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &stallPos, int cowCount, int distance) {
    int lastOccupiedPos = stallPos[0], occupiedStallCount = 1;
    for (int pos : stallPos) {
        if (lastOccupiedPos + distance <= pos) {
            lastOccupiedPos = pos;
            occupiedStallCount++;
        }
    }
    return occupiedStallCount >= cowCount;
}

void solve() {
    int stallCount, cowCount;
    cin >> stallCount >> cowCount;

    vector<int> stallPos(stallCount);
    for (int &pos : stallPos)
        cin >> pos;

    sort(stallPos.begin(), stallPos.end());

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(stallPos, cowCount, m))
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}