class Solution {
    void rec(vector<int> &a, int i, int sum, int target, int &res) {
        if (i == a.size()) {
            res += sum == target;
            return;
        }
        
        rec(a, i + 1, sum + a[i], target, res);
        rec(a, i + 1, sum - a[i], target, res);
    }
    
public:
    int findTargetSumWays(vector<int> &a, int target) {
        int res = 0;
        rec(a, 0, 0, target, res);
        return res;
    }
};