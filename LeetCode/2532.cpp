class Solution {
    struct Worker {
        int lr, r, rl, l, index;

        bool operator < (const Worker &that) const {
            if (lr + rl != that.lr + that.rl)
                return lr + rl > that.lr + that.rl;
            return index > that.index;
        }
    };

    struct Event {
        int time, index;
        enum { L, R, LR, RL, BRIDGE } type;

        bool operator < (const Event &that) const {
            if (time != that.time)
                return time < that.time;
            if (type != that.type)
                return type < that.type;
            return index < that.index;
        }
    };

public:
    int findCrossingTime(int boxCount, int workerCount, vector<vector<int>> workerData) {
        vector<Worker> workers;
        for (int i = 0; i < workerData.size(); i++)
            workers.push_back({ workerData[i][0], workerData[i][1], workerData[i][2], workerData[i][3], i });

        set<Worker> leftBank, rightBank;
        for (Worker &worker : workers)
            leftBank.insert(worker);

        set<Event> events;
        events.insert({ 0, -1, Event::BRIDGE });

        int deliveredCount = 0, takenCount = 0, res = 0;

        while (deliveredCount < boxCount) {
            auto [time, index, type] = *events.begin();
            events.erase(events.begin());

            if (type == Event::L) {
                deliveredCount++;
                if (takenCount < boxCount)
                    leftBank.insert(workers[index]);
            } else if (type == Event::R) {
                rightBank.insert(workers[index]);
            } else if (type == Event::LR) {
                events.insert({ time + workers[index].r, index, Event::R });
            } else if (type == Event::RL) {
                events.insert({ time + workers[index].l, index, Event::L });
                res = time;
            } else if (type == Event::BRIDGE) {
                if (!rightBank.empty()) {
                    Worker worker = *rightBank.begin();
                    rightBank.erase(rightBank.begin());
                    events.insert({ time + worker.rl, worker.index, Event::RL });
                    events.insert({ time + worker.rl, -1, Event::BRIDGE });
                } else if (!leftBank.empty() && takenCount < boxCount) {
                    Worker worker = *leftBank.begin();
                    leftBank.erase(leftBank.begin());
                    events.insert({ time + worker.lr, worker.index, Event::LR });
                    events.insert({ time + worker.lr, -1, Event::BRIDGE });
                    takenCount++;
                } else {
                    events.insert({ events.begin()->time, -1, Event::BRIDGE });
                }
            }
        }

        return res;
    }
};