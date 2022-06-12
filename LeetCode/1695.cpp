class Solution {
public:
    int maximumUniqueSubarray(vector<int> &a) {
        vector<int> seen(10001);
        int curSum = 0, maxSum = 0;
        
        for (int l = 0, r = 0; l < a.size(); l++) {
            while (r < a.size() && !seen[a[r]]) {
                curSum += a[r];
                seen[a[r]] = 1;
                r++;
            }
            
            maxSum = max(maxSum, curSum);

            curSum -= a[l];
            seen[a[l]] = 0;
        }
        
        return maxSum;
    }
};