#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    int shipmentCount;
    cin >> shipmentCount;

    map<string, int> toyCount;
    for (int i = 0; i < shipmentCount; i++) {
        string toy;
        int count;
        cin >> toy >> count;
        toyCount[toy] += count;
    }

    vector<pair<string, int>> pairs = { toyCount.begin(), toyCount.end() };
    sort(pairs.begin(), pairs.end(), compare);

    cout << pairs.size() << "\n";
    for (auto &[toy, count] : pairs)
        cout << toy << " " << count << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}