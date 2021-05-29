#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time, delta;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return delta > that.delta;
    }
};

bool solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    if (segmentCount < 0)
        return 0;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        events.push_back({ l, +1 });
        events.push_back({ r, -1 });
    }

    sort(events.begin(), events.end());

    int curSum = 0, maxSum = 0;
    for (auto &[_, delta] : events) {
        curSum += delta;
        maxSum = max(maxSum, curSum);
    }

    cout << "Case " << test << ": " << maxSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}