class Solution {
public:
    int countDistinct(vector<int> &a, int k, int mod) {
        set<vector<int>> subarrays;
        
        for (int l = 0; l < a.size(); l++) {
            vector<int> subarray;
            int divisible = 0;
            
            for (int r = l; r < a.size(); r++) {
                divisible += a[r] % mod == 0;
                if (divisible > k)
                    break;
                
                subarray.push_back(a[r]);
                subarrays.insert(subarray);
            }
        }
        
        return subarrays.size();
    }
};