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

    vector<pair<int, int>> a(6);
    for (auto &[h, w] : a) {
        cin >> h >> w;
        if (h > w)
            swap(h, w);
    }
    
    sort(a.begin(), a.end());

    if (a[0] == a[1] && a[2] == a[3] && a[4] == a[5] &&
        a[0].first == a[2].first && a[0].second == a[4].first && a[2].second == a[4].second)
        cout << "POSSIBLE";
    else
        cout << "IMPOSSIBLE";
}