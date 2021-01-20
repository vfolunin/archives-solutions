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

    map<int, int> eventInterval;
    set<pair<int, int>> eventQueue;

    while (1) {
        string reg;
        cin >> reg;
        if (reg == "#")
            break;

        int id, interval;
        cin >> id >> interval;
        eventInterval[id] = interval;
    }

    for (auto &[id, interval] : eventInterval)
        eventQueue.insert({ interval, id });

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        auto [time, id] = *eventQueue.begin();
        eventQueue.erase(eventQueue.begin());
        cout << id << "\n";
        eventQueue.insert({ time + eventInterval[id], id });
    }
}