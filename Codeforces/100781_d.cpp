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

    int eventCount, eventsPerServer;
    cin >> eventCount >> eventsPerServer;

    vector<pair<int, int>> events;
    for (int i = 0; i < eventCount; i++) {
        int time;
        cin >> time;
        events.push_back({ time, 1 });
        events.push_back({ time + 1000, -1 });
    }

    sort(events.begin(), events.end());

    int curEvents = 0, maxEvents = 0;
    for (auto &[time, delta] : events) {
        curEvents += delta;
        maxEvents = max(maxEvents, curEvents);
    }

    cout << (maxEvents + eventsPerServer - 1) / eventsPerServer;
}