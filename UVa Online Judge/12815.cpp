#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, stairsCount;
    cin >> h >> w >> stairsCount;

    vector<pair<int, int>> stairs(stairsCount);
    for (auto &[x, y] : stairs)
        cin >> x >> y;
    sort(stairs.begin(), stairs.end());

    string res = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (auto &[_, y] : stairs)
        swap(res[y - 1], res[y]);

    for (int i = 0; i < h; i++)
        cout << res[i] << (i + 1 < h ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}