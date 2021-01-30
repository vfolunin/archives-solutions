#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time;
    int index;
    bool turnsGreen;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        if (turnsGreen != that.turnsGreen)
            return !turnsGreen;
        return index < that.index;
    }
};

bool solve() {
    vector<int> period;
    while (1) {
        int p;
        cin >> p;

        if (!p)
            break;

        period.push_back(p);
    }

    if (period.empty())
        return 0;

    set<Event> events;
    for (int i = 0; i < period.size(); i++)
        events.insert({ period[i] - 5, i, 0 });

    int greenCount = period.size();
    while (1) {
        auto [time, index, turnsGreen] = *events.begin();
        events.erase(events.begin());

        if (turnsGreen) {
            greenCount++;
            events.insert({ time + period[index] - 5, index, 0 });
        } else {
            greenCount--;
            events.insert({ time + period[index] + 5, index, 1 });
        }

        if (greenCount == period.size()) {
            cout << setw(2) << setfill('0') << time / 3600 << ":";
            cout << setw(2) << setfill('0') << time % 3600 / 60 << ":";
            cout << setw(2) << setfill('0') << time % 60 << "\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}