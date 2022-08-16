struct Counter {
    map<int, int> count;
    int limit;

    Counter(int limit) : limit(limit) {}

    void add(int i, int delta) {
        count[i] += delta;
        if (!count[i])
            count.erase(i);
    }

    bool isOk() {
        return count.empty() || prev(count.end())->first - count.begin()->first <= limit;
    }
};

class Solution {
public:
    int longestSubarray(vector<int> &a, int limit) {
        Counter counter(limit);
        int res = 0;
        
        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (!counter.isOk()) {
                counter.add(a[l], -1);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};