struct Counter {
    unordered_map<int, int> count;
    set<pair<int, int>> counts;

    void add(int value, int delta) {
        counts.erase({ -count[value], value });
        if (count[value] += delta)
            counts.insert({ -count[value], value });
    }

    long long getBonus() {
        return -1LL * counts.begin()->first * counts.begin()->second;
    }
};

class Solution {
public:
    long long modeWeight(vector<int> &a, int windowSize) {
        Counter counter;
        for (int i = 0; i < windowSize; i++)
            counter.add(a[i], 1);
        long long res = counter.getBonus();

        for (int i = windowSize; i < a.size(); i++) {
            counter.add(a[i], 1);
            counter.add(a[i - windowSize], -1);
            res += counter.getBonus();
        }

        return res;
    }
};