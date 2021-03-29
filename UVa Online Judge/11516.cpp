#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &houses, int routerCount, int dist) {
    int last = -1e9, routerNeed = 0;
    for (int h : houses) {
        if (last + dist < h) {
            last = h + dist;
            routerNeed++;
        }
    }
    return routerNeed <= routerCount;
}

void solve() {
    int routerCount, houseCount;
    cin >> routerCount >> houseCount;

    vector<int> houses(houseCount);
    for (int &h : houses) {
        cin >> h;
        h *= 2;
    }

    sort(houses.begin(), houses.end());

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(houses, routerCount, m))
            r = m;
        else
            l = m;
    }

    cout << r / 2 << "." << (r % 2 ? 5 : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}