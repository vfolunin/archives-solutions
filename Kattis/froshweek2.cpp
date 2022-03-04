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

    int taskCount, intervalCount;
    cin >> taskCount >> intervalCount;

    multiset<int> tasks;
    for (int i = 0; i < taskCount; i++) {
        int time;
        cin >> time;
        tasks.insert(time);
    }

    multiset<int> intervals;
    for (int i = 0; i < intervalCount; i++) {
        int time;
        cin >> time;
        intervals.insert(time);
    }

    int res = 0;
    for (auto taskIt = tasks.rbegin(); taskIt != tasks.rend(); taskIt++) {
        auto intervalIt = intervals.lower_bound(*taskIt);
        if (intervalIt != intervals.end()) {
            res++;
            intervals.erase(intervalIt);
        }
    }

    cout << res;
}