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

    int eventCount, queryCount;
    cin >> eventCount >> queryCount;

    vector<pair<int, string>> events(eventCount);
    for (auto &[time, name] : events)
        cin >> time >> name;

    int prevTime = 0;
    for (int i = 0; i < queryCount; i++) {
        int checkTime;
        cin >> checkTime;

        for (auto &[time, name] : events)
            if (prevTime < time && time <= checkTime)
                cout << name << "\n";

        prevTime = checkTime;
    }
}