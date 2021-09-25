#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int ringCount;
    cin >> ringCount;

    vector<pair<int, int>> rings(ringCount);
    int maxR1 = -2;

    for (int i = 0; i < rings.size(); i++) {
        cin >> rings[i].first >> rings[i].second;
        if (maxR1 == -2 || rings[i].first > rings[maxR1].first)
            maxR1 = i;
    }

    for (int i = 0; i < rings.size(); i++) {
        if (i != maxR1 && rings[i].second > rings[maxR1].first) {
            maxR1 = -2;
            break;
        }
    }

    cout << maxR1 + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}