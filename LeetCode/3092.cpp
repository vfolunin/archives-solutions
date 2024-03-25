struct Counter {
    unordered_map<int, long long> count;
    multiset<long long> counts;

    void add(int value, int delta) {
        if (count.count(value))
            counts.erase(counts.find(count[value]));
        count[value] += delta;
        counts.insert(count[value]);
    }
};

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int> &values, vector<int> &counts) {
        Counter counter;
        vector<long long> res(values.size());

        for (int i = 0; i < res.size(); i++) {
            counter.add(values[i], counts[i]);
            res[i] = *prev(counter.counts.end());
        }

        return res;
    }
};