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

    int h, w, cellCount;
    cin >> h >> w >> cellCount;

    vector<int> ys = { 0, h + 1 };
    vector<int> xs = { 0, w + 1 };
    for (int i = 0; i < cellCount; i++) {
        int y, x;
        cin >> y >> x;

        ys.push_back(y);
        xs.push_back(x);
    }
    sort(ys.begin(), ys.end());
    sort(xs.begin(), xs.end());

    int maxDY = 0;
    for (int i = 0; i + 1 < ys.size(); i++)
        maxDY = max(maxDY, ys[i + 1] - ys[i] - 1);

    int maxDX = 0;
    for (int i = 0; i + 1 < xs.size(); i++)
        maxDX = max(maxDX, xs[i + 1] - xs[i] - 1);

    cout << maxDY * maxDX;
}