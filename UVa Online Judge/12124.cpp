#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int componentCount, budget;
    cin >> componentCount >> budget;

    map<string, vector<pair<int, int>>> components;
    for (int i = 0; i < componentCount; i++) {
        string type, name;
        int price, quality;
        cin >> type >> name >> price >> quality;
        components[type].push_back({ quality, price });
    }

    for (auto &[_, v] : components) {
        sort(v.begin(), v.end());
        for (int i = (int)v.size() - 2; i >= 0; i--)
            v[i].second = min(v[i].second, v[i + 1].second);
        v.push_back({ 1e9, 1e9 });
    }

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;

        long long budgetNeeded = 0;
        for (auto &[_, v] : components)
            budgetNeeded += lower_bound(v.begin(), v.end(), make_pair(m, 0))->second;
        
        if (budgetNeeded <= budget)
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}