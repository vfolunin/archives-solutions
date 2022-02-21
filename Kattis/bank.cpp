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

    int jobCount, limit;
    cin >> jobCount >> limit;

    vector<pair<int, int>> jobs(jobCount);
    for (auto &[cost, deadline] : jobs)
        cin >> cost >> deadline;

    sort(jobs.rbegin(), jobs.rend());

    vector<int> slots(limit + 1);
    int res = 0;
    for (auto &[cost, deadline] : jobs) {
        while (deadline >= 0 && slots[deadline])
            deadline--;
        if (deadline >= 0) {
            slots[deadline] = 1;
            res += cost;
        }
    }

    cout << res;
}