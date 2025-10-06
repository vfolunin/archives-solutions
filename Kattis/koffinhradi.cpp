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

    int taskCount;
    cin >> taskCount;

    map<int, vector<int>> tasks;
    for (int i = 0; i < taskCount; i++) {
        int duration, deadline;
        cin >> duration >> deadline;

        tasks[deadline].push_back(duration);
    }

    multiset<int> sortedDurations;
    long long sum = 0;
    int res = 0;

    for (auto &[deadline, durations] : tasks) {
        for (int duration : durations) {
            sortedDurations.insert(duration);
            sum += duration;
        }

        while (sum > deadline) {
            int duration = *prev(sortedDurations.end());
            sortedDurations.erase(prev(sortedDurations.end()));
            sum -= duration;

            res++;
            duration /= 2;

            sortedDurations.insert(duration);
            sum += duration;
        }
    }

    cout << res;
}