class Solution {
    void rec(vector<int> &count, int i, vector<int> &curCount, int curSum, int targetSum, vector<vector<int>> &res) {
        if (curSum == targetSum) {
            res.emplace_back();
            for (int value = 0; value < curCount.size(); value++)
                for (int i = 0; i < curCount[value]; i++)
                    res.back().push_back(value);
            return;
        }
        
        if (i == curCount.size() || curSum > targetSum)
            return;
        
        for (curCount[i] = 0; curCount[i] <= count[i]; curCount[i]++)
            rec(count, i + 1, curCount, curSum + curCount[i] * i, targetSum, res);
        curCount[i] = 0;
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int> &a, int targetSum) {
        vector<int> count(51);
        for (int value : a)
            count[value]++;
        
        vector<vector<int>> res;
        vector<int> curCount(51);
        rec(count, 1, curCount, 0, targetSum, res);
        return res;
    }
};