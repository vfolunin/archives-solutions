#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, int> totalCount, totalCost;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        unordered_map<string, int> curCost;
        for (int j = 0; j < s.size(); j++) {
            if (!curCost.count(s))
                curCost[s] = j;
            rotate(s.begin(), s.begin() + 1, s.end());
        }

        for (auto &[s, cost] : curCost) {
            totalCount[s]++;
            totalCost[s] += cost;
        }
    }

    int res = 1e9;
    for (auto &[s, cost] : totalCost)
        if (totalCount[s] == size)
            res = min(res, cost);

    cout << (res < 1e9 ? res : -1);
}