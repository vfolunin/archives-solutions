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

    int viewpointCount, maxDiff;
    cin >> viewpointCount >> maxDiff;

    vector<int> height(viewpointCount);
    for (int &h : height)
        cin >> h;

    int res = 1;
    for (int l = 0, r = 0; l < viewpointCount; l++) {
        r = max(r, l);
        while (r + 1 < viewpointCount && height[r + 1] - height[r] <= maxDiff)
            r++;
        res = max(res, r - l + 1);
    }

    cout << res << "\n";
}