#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> canMake(1e6 + 1);
    canMake[0] = 1;

    for (int itemWeight = 1, factor = 1; itemWeight < canMake.size(); itemWeight *= factor, factor++)
        for (int weight = canMake.size() - 1; weight >= itemWeight; weight--)
            canMake[weight] |= canMake[weight - itemWeight];

    return canMake;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> canMake = prepare();

    cout << (canMake[n] ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}