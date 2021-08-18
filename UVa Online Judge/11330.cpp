#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int shoeCount;
    cin >> shoeCount;

    vector<int> color(2 * shoeCount);
    map<int, set<int>> pos;

    for (int i = 0; i < color.size(); i++) {
        cin >> color[i];
        pos[color[i]].insert(i);
    }

    int res = 0;
    for (int i = 0; i < color.size(); i += 2) {
        pos[color[i]].erase(i);
        if (color[i] == color[i + 1]) {
            pos[color[i]].erase(i + 1);
        } else {
            res++;
            int pa = *pos[color[i]].begin();
            int pb = *pos[color[i + 1]].begin();
            pos[color[i]].erase(pa);
            pos[color[i + 1]].erase(pb);
            pos[color[i + 1]].insert(pa);
            swap(color[pa], color[pb]);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}