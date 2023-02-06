class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>> &a) {
        map<int, int> count;
        for (vector<int> &row : a)
            for (int value : row)
                count[value]++;

        vector<int> res;
        for (auto &[value, count] : count)
            if (count == a.size())
                res.push_back(value);
        return res;
    }
};