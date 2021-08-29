#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    vector<int> x(pointCount), y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    vector<int> dist;
    for (int i = 0; i < pointCount; i++) {
        for (int j = i + 1; j < pointCount; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            dist.push_back(dx * dx + dy * dy);
        }
    }

    sort(dist.begin(), dist.end());
    int res = unique(dist.begin(), dist.end()) - dist.begin();

    cout << "Case " << test << ": " << res + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}