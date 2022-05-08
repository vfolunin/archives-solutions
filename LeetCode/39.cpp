class Solution {
    void rec(vector<int> &a, int i, int sum, int targetSum, vector<int> &combination, vector<vector<int>> &combinations) {
        if (i == a.size() || sum > targetSum)
            return;
        
        if (sum == targetSum) {
            combinations.push_back(combination);
            return;
        }
        
        combination.emplace_back();
        for (int nextI = i; nextI < a.size(); nextI++) {
            combination.back() = a[nextI];
            rec(a, nextI, sum + a[nextI], targetSum, combination, combinations);
        }
        combination.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum(vector<int> &a, int targetSum) {
        vector<int> combination;
        vector<vector<int>> combinations;
        rec(a, 0, 0, targetSum, combination, combinations);
        return combinations;
    }
};