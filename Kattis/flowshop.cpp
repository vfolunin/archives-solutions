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

    int itemCount, stageCount;
    cin >> itemCount >> stageCount;

    vector<vector<int>> time(itemCount, vector<int>(stageCount));
    for (int item = 0; item < itemCount; item++)
        for (int stage = 0; stage < stageCount; stage++)
            cin >> time[item][stage];

    set<pair<int, int>> q;
    for (int item = 0; item < itemCount; item++)
        q.insert({ 0, item });

    for (int stage = 0; stage < stageCount; stage++) {
        int curTime = 0;
        set<pair<int, int>> nextQ;

        while (!q.empty()) {
            auto [itemTime, item] = *q.begin();
            q.erase(q.begin());

            curTime = max(curTime, itemTime) + time[item][stage];
            nextQ.insert({ curTime, item });
        }

        q.swap(nextQ);
    }

    vector<int> res(itemCount);
    for (auto &[time, item] : q)
        res[item] = time;

    for (int time : res)
        cout << time << " ";
}