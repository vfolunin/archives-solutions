#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

struct Event {
    int time;
    int id;
    enum { Y, R, G } color;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        if (color != that.color)
            return color < that.color;
        return id < that.id;
    }
};

bool solve(int test) {
    vector<int> intervals = readInts();
    if (intervals.empty())
        return 0;

    set<Event> events;
    for (int i = 0; i < intervals.size(); i++)
        events.insert({ intervals[i] - 5, i, Event::Y });

    int greenCount = intervals.size();
    while (1) {
        auto [time, id, color] = *events.begin();
        events.erase(events.begin());

        if (time > 60 * 60) {
            cout << "Set " << test << " is unable to synch after one hour.\n";
            break;
        }

        if (color == Event::Y) {
            greenCount--;
            events.insert({ time + 5, id, Event::R });
        } else if (color == Event::R) {
            events.insert({ time + intervals[id], id, Event::G });
        } else {
            greenCount++;
            events.insert({ time + intervals[id] - 5, id, Event::Y });
        }

        if (greenCount == intervals.size()) {
            cout << "Set " << test << " synchs again at ";
            cout << time / 60 << " minute(s) and ";
            cout << time % 60 << " second(s) after all turning green.\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}