#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &pos, int cowCount, int dist) {
    int lastPos = pos[0], placedCount = 1;
    for (int p : pos) {
        if (lastPos + dist <= p) {
            lastPos = p;
            placedCount++;
        }
    }
    return placedCount >= cowCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stallCount, cowCount;
    cin >> stallCount >> cowCount;

    vector<int> pos(stallCount);
    for (int &p : pos)
        cin >> p;

    sort(pos.begin(), pos.end());

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(pos, cowCount, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}