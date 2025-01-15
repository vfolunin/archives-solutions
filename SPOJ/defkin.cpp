#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, size;
    cin >> h >> w >> size;

    vector<int> ys = { 0, h + 1 };
    vector<int> xs = { 0, w + 1 };

    for (int i = 0; i < size; i++) {
        int y, x;
        cin >> y >> x;

        ys.push_back(y);
        xs.push_back(x);
    }

    sort(ys.begin(), ys.end());
    sort(xs.begin(), xs.end());

    int dy = 0;
    for (int i = 0; i + 1 < ys.size(); i++)
        dy = max(dy, ys[i + 1] - ys[i] - 1);

    int dx = 0;
    for (int i = 0; i + 1 < xs.size(); i++)
        dx = max(dx, xs[i + 1] - xs[i] - 1);

    cout << dy * dx << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}