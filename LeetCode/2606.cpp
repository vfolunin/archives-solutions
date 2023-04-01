class Solution {
public:
    int maximumCostSubstring(string &s, string &letters, vector<int> &costs) {
        int prefixSum = 0, minPrefixSum = 0, res = 0;
        
        for (char c : s) {
            if (int i = letters.find(c); i != -1)
                prefixSum += costs[i];
            else
                prefixSum += c - 'a' + 1;
            
            res = max(res, prefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
        }
        
        return res;
    }
};