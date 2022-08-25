class Solution {
    bool rec(vector<int> &a, int i, vector<int> &sums, int sum) {
        if (i == a.size())
            return 1;
        
        for (int j = 0; j < sums.size(); j++) {
            if (j && sums[j - 1] == sums[j])
                continue;
            if (sums[j] + a[i] <= sum) {
                sums[j] += a[i];
                if (rec(a, i + 1, sums, sum))
                    return 1;
                sums[j] -= a[i];
            }
        }
        
        return 0;
    }
    
public:
    bool canPartitionKSubsets(vector<int> &a, int k) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % k)
            return 0;
        
        sort(a.rbegin(), a.rend());
        
        vector<int> sums(k);
        return rec(a, 0, sums, sum / k);
    }
};