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

    int buildingCount;
    cin >> buildingCount;

    vector<int> height(buildingCount);
    for (int &h : height)
        cin >> h;

    sort(height.begin(), height.end());

    int res = buildingCount;
    for (int i = 0; i < buildingCount; i++)
        res = min(res, height[i] + buildingCount - 1 - i);

    cout << res << "\n";
}