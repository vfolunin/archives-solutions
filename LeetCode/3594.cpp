struct State {
    int mask, side, factorIndex;

    State(int mask, int side, int factorIndex) : mask(mask), side(side), factorIndex(factorIndex) {}

    bool operator == (const State &that) const {
        return tie(mask, side, factorIndex) == tie(that.mask, that.side, that.factorIndex);
    }

    bool operator < (const State &that) const {
        return tie(mask, side, factorIndex) < tie(that.mask, that.side, that.factorIndex);
    }
};

template<>
struct hash<State> {
    size_t operator() (const State &state) const {
        return (state.mask * 2 + state.side) * 5 + state.factorIndex;
    }
};

class Solution {
    double dijkstra(int seatCount, vector<int> &time, vector<double> &factor) {
        unordered_map<State, double> dist;
        set<pair<double, State>> q;

        State start((1 << time.size()) - 1, 0, 0);
        dist[start] = 0;
        q.insert({ dist[start], start });

        while (!q.empty()) {
            State v = q.begin()->second;
            q.erase(q.begin());

            auto [mask, side, factorIndex] = v;
            if (!mask && side)
                return dist[v];

            vector<pair<State, double>> edges;

            if (!side) {
                for (int submask = mask; submask; submask = (submask - 1) & mask) {            
                    int ones = 0, maxTime = 0;
                    for (int bit = 0; bit < time.size(); bit++) {
                        if (submask & (1 << bit)) {
                            ones++;
                            maxTime = max(maxTime, time[bit]);
                        }
                    }
                    
                    if (ones > seatCount)
                        continue;

                    double weight = maxTime * factor[factorIndex];
                    State to(mask ^ submask, !side, (factorIndex + (int)weight) % factor.size());
                    edges.push_back({ to, weight });
                }
            } else {
                for (int bit = 0; bit < time.size(); bit++) {
                    if (!(mask & (1 << bit))) {
                        double weight = time[bit] * factor[factorIndex];
                        State to(mask ^ (1 << bit), !side, (factorIndex + (int)weight) % factor.size());
                        edges.push_back({ to, weight });
                    }
                }
            }

            for (auto &[to, weight] : edges) {
                if (!dist.count(to) || dist[to] > dist[v] + weight) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return -1;
    }

public:
    double minTime(int humanCount, int seatCount, int factorCount, vector<int> &time, vector<double> &factor) {
        return dijkstra(seatCount, time, factor);
    }
};