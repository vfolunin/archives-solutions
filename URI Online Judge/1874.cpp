#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}

bool solve() {
    int h, w, valCount;
    cin >> h >> w >> valCount;

    if (!h && !w && !valCount)
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> spaces;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (!a[y][x])
                spaces.push_back({ y, x });
        }
    }

    vector<int> vals(valCount);
    for (int &val : vals)
        cin >> val;

    sort(spaces.begin(), spaces.end(), compare);

    for (int i = 0; i < spaces.size() && i < vals.size(); i++)
        a[spaces[i].first][spaces[i].second] = vals[i];

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cout << a[y][x] << (x + 1 < w ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}