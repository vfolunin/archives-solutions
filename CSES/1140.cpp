#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Project {
    int l, r, cost;

    bool operator < (const Project &that) const {
        return r < that.r;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int projectCount;
    cin >> projectCount;

    vector<Project> projects(projectCount);
    for (auto &[l, r, cost] : projects)
        cin >> l >> r >> cost;

    sort(projects.begin(), projects.end());
    map<int, long long> maxCost = { {0, 0} };

    for (auto &[l, r, cost] : projects) {
        if (!maxCost.count(r))
            maxCost[r] = maxCost.rbegin()->second;
        maxCost[r] = max(maxCost[r], (--maxCost.lower_bound(l))->second + cost);
    }

    cout << maxCost.rbegin()->second;
}