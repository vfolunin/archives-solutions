struct Counter {
    unordered_map<int, int> count;
    int duplicateCount = 0;
    
    void add(int value) {
        count[value]++;
        if (count[value] == 2)
            duplicateCount += 2;
        else if (count[value] > 2)
            duplicateCount++;
    }
};

class Solution {
public:
    int minCost(vector<int> &a, int price) {
        vector<long long> cost(a.size() + 1, 1e18);
        cost[0] = 0;
        
        for (int size = 1; size <= a.size(); size++) {
            Counter counter;
            for (int partSize = 1; partSize <= size; partSize++) {
                counter.add(a[size - partSize]);
                cost[size] = min(cost[size], cost[size - partSize] + counter.duplicateCount + price);
            }
        }
        
        return cost.back();
    }
};