class Solution {
    void rec(int count, int targetCount, int sum, int targetSum,
             vector<int> &combination, vector<vector<int>> &combinations) {
        if (count > targetCount || sum > targetSum)
            return;
        
        if (count == targetCount && sum == targetSum) {
            combinations.push_back(combination);
            return;
        }
        
        int from = combination.empty() ? 1 : combination.back() + 1;
        combination.emplace_back();
        for (int i = from; i < 10; i++) {
            combination.back() = i;
            rec(count + 1, targetCount, sum + i, targetSum, combination, combinations);
        }
        combination.pop_back();
    }
        
public:
    vector<vector<int>> combinationSum3(int targetCount, int targetSum) {
        vector<int> combination;
        vector<vector<int>> combinations;
        rec(0, targetCount, 0, targetSum, combination, combinations);
        return combinations;
    }
};