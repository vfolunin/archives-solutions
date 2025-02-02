struct Event {
    int time;
    enum Type { IN, OUT, MESSAGE } type;
    vector<int> ids;

    Event(int time, Event::Type type, const vector<int> &ids) :
        time(time), type(type), ids(ids) {}

    Event(vector<string> &args) {
        type = args[0] == "MESSAGE" ? Event::MESSAGE : Event::OUT;

        time = stoi(args[1]);

        if (args[2] == "ALL") {
            ids = { -1 };
        } else if (args[2] == "HERE") {
            ids = { -2 };
        } else {
            ids.emplace_back();
            for (char c : args[2])
                if (isdigit(c))
                    ids.back() = ids.back() * 10 + c - '0';
                else if (c == ' ')
                    ids.emplace_back();
        }
    }

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

class Solution {
public:
    vector<int> countMentions(int userCount, vector<vector<string>> &eventArgs) {
        vector<Event> events;
        for (vector<string> &eventArgs : eventArgs) {
            events.emplace_back(eventArgs);
            if (events.back().type == Event::OUT)
                events.push_back({ events.back().time + 60, Event::IN, events.back().ids });
        }
        sort(events.begin(), events.end());

        vector<int> online(userCount, 1), res(userCount);
        for (auto &[time, type, ids] : events) {
            if (type == Event::IN) {
                online[ids[0]] = 1;
            } else if (type == Event::OUT) {
                online[ids[0]] = 0;
            } else {
                if (ids[0] == -1) {
                    for (int id = 0; id < userCount; id++)
                        res[id]++;
                } else if (ids[0] == -2) {
                    for (int id = 0; id < userCount; id++)
                        if (online[id])
                            res[id]++;
                } else {
                    for (int id : ids)
                        res[id]++;
                }
            }
        }

        return res;
    }
};