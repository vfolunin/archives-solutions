#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int storeCount;
    cin >> storeCount;

    vector<int> storePosition(storeCount);
    for (int &position : storePosition)
        cin >> position;

    auto [l, r] = minmax_element(storePosition.begin(), storePosition.end());
    cout << 2 * (*r - *l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}