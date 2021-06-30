#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int parliamentSize;
    cin >> parliamentSize;

    vector<int> groups;
    int groupSum = 0;

    for (int group = 2; groupSum < parliamentSize; group++) {
        groups.push_back(group);
        groupSum += group;
    }

    if (groupSum - parliamentSize > 1) {
        groups.erase(find(groups.begin(), groups.end(), groupSum - parliamentSize));
    } else if (groupSum - parliamentSize == 1) {
        groups.erase(groups.begin());
        groups.back()++;
    }

    if (test)
        cout << "\n";
    for (int i = 0; i < groups.size(); i++)
        cout << groups[i] << (i + 1 < groups.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}