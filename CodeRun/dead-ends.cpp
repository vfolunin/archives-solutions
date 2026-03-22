#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    int time;
    enum { IN, OUT } type;
    int index;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int slotCount, trainCount;
    cin >> slotCount >> trainCount;

    vector<Event> events;

    for (int i = 0; i < trainCount; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        events.push_back({ t1, Event::IN, i });
        events.push_back({ t2, Event::OUT, i });
    }

    sort(events.begin(), events.end());

    set<int> freeSlots;
    for (int slot = 0; slot < slotCount; slot++)
        freeSlots.insert(slot);

    vector<int> res(trainCount);
    for (auto &[time, type, index] : events) {
        if (type == Event::IN) {
            if (freeSlots.empty()) {
                cout << "0 " << index + 1;
                return 0;
            }
            res[index] = *freeSlots.begin();
            freeSlots.erase(freeSlots.begin());
        } else {
            freeSlots.insert(res[index]);
        }
    }

    for (int slot : res)
        cout << slot + 1 << "\n";
}