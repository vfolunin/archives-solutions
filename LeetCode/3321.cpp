struct Counter {
    int rSize;
    long long rSum = 0;
    unordered_map<int, int> count;
    set<pair<int, int>> l, r;

    Counter(int rSize) : rSize(rSize) {}

    void rebalance() {
        while (r.size() < rSize && !l.empty()) {
            r.insert(*prev(l.end()));
            rSum += 1LL * r.begin()->first * r.begin()->second;
            l.erase(prev(l.end()));
        }
        while (r.size() > rSize) {
            l.insert(*r.begin());
            rSum -= 1LL * r.begin()->first * r.begin()->second;
            r.erase(r.begin());
        }
    }

    void add(int value, int delta) {
        if (l.count({ count[value], value })) {
            l.erase({ count[value], value });
        } else if (r.count({ count[value], value })) {
            rSum -= 1LL * count[value] * value;
            r.erase({ count[value], value });
        }
        rebalance();

        count[value] += delta;
        if (!count[value])
            return;
            
        if (r.size() < rSize || *r.begin() < make_pair(count[value], value)) {
            r.insert({ count[value], value });
            rSum += 1LL * count[value] * value;
        } else {
            l.insert({ count[value], value });
        }
        rebalance();
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int> &a, int width, int limit) {
        Counter counter(limit);
        for (int i = 0; i < width; i++)
            counter.add(a[i], 1);

        vector<long long> res = { counter.rSum };
        for (int l = 0, r = width; r < a.size(); l++, r++) {
            counter.add(a[l], -1);
            counter.add(a[r], 1);
            res.push_back(counter.rSum);
        }
        return res;
    }
};