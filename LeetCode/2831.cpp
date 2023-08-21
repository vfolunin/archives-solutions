struct Counter {
    unordered_map<int, int> count;
    multiset<int> counts;
    int countSum = 0;

    void add(int value, int delta) {
        if (count[value]) {
            counts.erase(counts.find(count[value]));
            countSum -= count[value];
        }

        count[value] += delta;
        
        if (count[value]) {
            counts.insert(count[value]);
            countSum += count[value];
        }
    }

    int lesserCountSum() {
        return counts.empty() ? 0 : countSum - *prev(counts.end());
    }
};

class Solution {
public:
    int longestEqualSubarray(vector<int> &a, int k) {
        Counter counter;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (counter.lesserCountSum() > k) {
                counter.add(a[l], -1);
                l++;
            }
            res = max(res, r - l + 1 - counter.lesserCountSum());
        }

        return res;
    }
};