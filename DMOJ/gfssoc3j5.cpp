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

    int pairCount;
    cin >> pairCount;

    vector<pair<int, int>> pairs(pairCount);
    int totalWeight = 0;
    for (auto &[floor, weight] : pairs) {
        cin >> floor >> weight;
        totalWeight += weight;
    }

    sort(pairs.begin(), pairs.end());
    int res = 1e9;

    do {
        int cur = 0, curFloor = 101, curWeight = totalWeight;
        for (auto &[floor, weight] : pairs) {
            cur += (abs(curFloor - floor) + 1) * curWeight;
            curFloor = floor;
            curWeight -= weight;
        }
        res = min(res, cur);
    } while (next_permutation(pairs.begin(), pairs.end()));

    cout << res;
}