#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int jobCount, targetJob;
    cin >> jobCount >> targetJob;

    deque<pair<int, int>> jobs(jobCount);
    multiset<int> priorities;

    for (int i = 0; i < jobCount; i++) {
        jobs[i].first = i;
        cin >> jobs[i].second;
        priorities.insert(jobs[i].second);
    }

    int time = 0;
    while (1) {
        auto [job, priority] = jobs.front();
        jobs.pop_front();
        priorities.erase(priorities.find(priority));

        if (!priorities.empty() && *priorities.rbegin() > priority) {
            jobs.push_back({ job, priority });
            priorities.insert(priority);
        } else {
            time++;
            if (job == targetJob)
                break;
        }
    }

    cout << time << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}