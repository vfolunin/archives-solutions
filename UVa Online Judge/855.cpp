#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int pointCount;
    cin >> pointCount >> pointCount >> pointCount;

    vector<int> xs(pointCount), ys(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> xs[i] >> ys[i];

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int mid = (pointCount - 1) / 2;

    cout << "(Street: " << xs[mid] << ", Avenue: " << ys[mid] << ")\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}