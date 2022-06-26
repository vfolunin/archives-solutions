class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &a, int k) {
        vector<int> res(a.size() + 1);
        
        for (int size = 1; size <= a.size(); size++) {
            int partValue = 0;
            for (int partSize = 1; partSize <= k && partSize <= size; partSize++) {
                partValue = max(partValue, a[size - partSize]);
                res[size] = max(res[size], res[size - partSize] + partValue * partSize);
            }
        }
        
        return res.back();
    }
};