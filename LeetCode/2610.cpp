class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &a) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int value : a)
            maxCount = max(maxCount, ++count[value]);
        
        vector<vector<int>> res(maxCount);
        for (auto &[value, count] : count)
            for (int i = 0; i < count; i++)
                res[i].push_back(value);
        return res;
    }
};