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

    int size, minDist;
    cin >> size >> minDist;

    vector<pair<int, int>> pos(size);
    for (int i = 0; i < pos.size(); i++) {
        cin >> pos[i].first;
        pos[i].second = i;
    }

    sort(pos.begin(), pos.end());

    int taskCount = 0;
    for (int l = 0, r = 0; l < pos.size(); l++) {
        while (r < pos.size() && pos[r].first - pos[l].first <= minDist)
            r++;
        taskCount = max(taskCount, r - l);
    }

    vector<int> task(pos.size());
    for (int i = 0; i < task.size(); i++)
        task[pos[i].second] = i % taskCount + 1;

    cout << taskCount << "\n";
    for (int t : task)
        cout << t << " ";
}