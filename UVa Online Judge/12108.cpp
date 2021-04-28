#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time, student;
    enum { SLEEP, AWAKE } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        if (type != that.type)
            return type < that.type;
        return student < that.student;
    }
};

bool solve(int test) {
    int studentCount;
    cin >> studentCount;

    if (!studentCount)
        return 0;

    vector<int> awakePeriod(studentCount);
    vector<int> sleepPeriod(studentCount);
    vector<int> start(studentCount);
    int awakeCount = 0;
    set<Event> events;

    for (int i = 0; i < studentCount; i++) {
        cin >> awakePeriod[i] >> sleepPeriod[i] >> start[i];
        if (start[i] <= awakePeriod[i]) {
            awakeCount++;
            events.insert({ awakePeriod[i] - start[i] + 2, i, Event::SLEEP });
        } else {
            events.insert({ awakePeriod[i] + sleepPeriod[i] - start[i] + 2, i, Event::AWAKE });
        }
    }

    if (awakeCount == studentCount) {
        cout << "Case " << test << ": 1\n";
        return 1;
    }

    while (1) {
        auto [time, student, type] = *events.begin();
        events.erase(events.begin());

        if (type == Event::SLEEP) {
            if (awakeCount < studentCount - awakeCount) {
                awakeCount--;
                events.insert({ time + sleepPeriod[student], student, Event::AWAKE });
            } else {
                events.insert({ time + awakePeriod[student], student, Event::SLEEP });
            }
        } else {
            awakeCount++;
            events.insert({ time + awakePeriod[student], student, Event::SLEEP });
        }

        if (awakeCount == studentCount || time >= 1e5) {
            cout << "Case " << test << ": " << (time < 1e5 ? time : -1) << "\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}