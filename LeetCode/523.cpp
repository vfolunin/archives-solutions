class Solution {
public:
    bool checkSubarraySum(vector<int> &a, int mod) {        
        int sum = 0;
        unordered_map<int, int> seen = { { 0, -1 } };
        
        for (int i = 0; i < a.size(); i++) {
            sum = (sum + a[i]) % mod;    
            if (!seen.count(sum))
                seen[sum] = i;
            else if (i - seen[sum] >= 2)
                return 1;
        }
        
        return 0;
    }
};