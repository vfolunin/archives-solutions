class Solution {
public:
    int maxNonOverlapping(vector<int> &a, int targetSum) {
        unordered_map<int, int> seen = { { 0, -1 } };
        int sum = 0, prevEnd = -1, res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            if (seen.count(sum - targetSum) && prevEnd <= seen[sum - targetSum]) {
                prevEnd = i;
                res++;
            }
            seen[sum] = i;
        }
        
        return res;
    }
};