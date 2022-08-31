class Solution {
public:
    int minSumOfLengths(vector<int> &a, int targetSum) {
        vector<int> to(a.size(), -1);
        
        for (int l = 0, r = 0, sum = 0; l < a.size(); l++) {
            while (r < a.size() && sum < targetSum) {
                sum += a[r];
                r++;
            }
            
            if (sum == targetSum)
                to[l] = r - 1;
            
            sum -= a[l];
        }
        
        vector<int> after(a.size(), 1e9);
        
        for (int i = a.size() - 1; i >= 0; i--) {
            if (i + 1 < a.size())
                after[i] = after[i + 1];
            
            if (to[i] != -1)
                after[i] = min(after[i], to[i] - i + 1);
        }
        
        int res = 1e9;
        
        for (int i = 0; i < a.size(); i++)
            if (to[i] != -1 && to[i] + 1 < a.size())
                res = min(res, to[i] - i + 1 + after[to[i] + 1]);
        
        return res != 1e9 ? res : -1;
    }
};