#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Task {
    int duration, deadline;

    bool operator < (const Task &that) const {
        return duration < that.duration;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int taskCount;
    cin >> taskCount;

    vector<Task> tasks(taskCount);
    for (auto &[duration, deadline] : tasks)
        cin >> duration >> deadline;

    sort(tasks.begin(), tasks.end());

    long long res = 0, time = 0;
    for (auto &[duration, deadline] : tasks) {
        time += duration;
        res += deadline - time;
    }

    cout << res;
}