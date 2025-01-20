#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

struct Event {
    enum { BEGIN, END } type;
    int index;
};

void solve() {
    int segmentCount;
    cin >> segmentCount;

    map<int, vector<Event>> events;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        events[l].push_back({ Event::BEGIN, i });
        events[r].push_back({ Event::END, i });
    }

    if (0 < events.begin()->first || events.rbegin()->first < 10000) {
        cout << "Wrong Answer\n";
        return;
    }

    vector<int> critical(segmentCount);
    unordered_set<int> guards;
    for (auto &[time, events] : events) {
        for (auto &[type, index] : events) {
            if (type == Event::BEGIN)
                guards.insert(index);
            else
                guards.erase(index);
        }

        if (guards.empty() && 0 < time && time < 10000) {
            cout << "Wrong Answer\n";
            return;
        }

        if (guards.size() == 1)
            critical[*guards.begin()] = 1;
    }

    cout << (count(critical.begin(), critical.end(), 0) ? "Wrong Answer\n" : "Accepted\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}