class Solution {
public:
    int minOperations(vector<int> &a, int target) {
        int sum = 0;
        for (int value : a)
            sum += value;        
        target = sum - target;
        
        int res = -1;
        
        for (int l = 0, r = 0, sum = 0; l < a.size(); l++) {
            while (r < a.size() && sum + a[r] <= target) {
                sum += a[r];
                r++;
            }
            
            if (sum == target)
                res = max(res, r - l);
            
            sum -= a[l];
        }
        
        return res == -1 ? res : a.size() - res;
    }
};