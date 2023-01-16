struct Counter {
    unordered_map<int, long long> count;
    int limit;
    long long pairCount = 0;

    Counter(int limit) : limit(limit) {}

    void add(int i, int delta) {
        pairCount -= count[i] * (count[i] - 1) / 2;
        count[i] += delta;
        pairCount += count[i] * (count[i] - 1) / 2;
    }

    bool isOk() {
        return pairCount >= limit;
    }
};

class Solution {
public:
    long long countGood(vector<int> &a, int limit) {
        Counter counter(limit);
        long long res = 0;
        
        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (counter.isOk()) {
                counter.add(a[l], -1);
                l++;
            }
            
            res += l;
        }
        
        return res;
    }
};