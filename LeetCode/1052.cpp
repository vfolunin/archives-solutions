class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int left = 0, mid = 0, right = 0;
        for (int i = 0; i < minutes; i++)
            mid += customers[i];
        for (int i = minutes; i < customers.size(); i++)
            if (!grumpy[i])
                right += customers[i];
        
        int res = left + mid + right;
        
        for (int l = 1, r = minutes; r < customers.size(); l++, r++) {
            if (!grumpy[l - 1])
                left += customers[l - 1];
            mid += customers[r] - customers[l - 1];
            if (!grumpy[r])
                right -= customers[r];
            
            res = max(res, left + mid + right);
        }
        
        return res;
    }
};