struct Counter {
    unordered_map<int, int> count;
    int distinct = 0;
    long long sum = 0;
    
    void add(int value) {
        count[value]++;
        distinct += count[value] == 1;
        sum += value;
    }
    
    void remove(int value) {
        count[value]--;
        distinct -= count[value] == 0;
        sum -= value;
    }
};

class Solution {
public:
    long long maxSum(vector<int> &a, int limit, int width) {
        Counter counter;
        for (int i = 0; i < width; i++)
            counter.add(a[i]);
        
        long long res = 0;
        if (counter.distinct >= limit)
            res = max(res, counter.sum);
        
        for (int i = width; i < a.size(); i++) {
            counter.remove(a[i - width]);
            counter.add(a[i]);
            if (counter.distinct >= limit)
                res = max(res, counter.sum);
        }
        
        return res;
    }
};