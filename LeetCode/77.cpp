class Solution {
    void rec(int n, int k, vector<vector<int>> &combinations, vector<int> &combination) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }
        
        combination.push_back(combination.empty() ? 1 : combination.back() + 1);
        for (; combination.back() <= n; combination.back()++)
            rec(n, k, combinations, combination);
        combination.pop_back();
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        rec(n, k, combinations, combination);
        return combinations;
    }
};