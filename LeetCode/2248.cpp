class Solution {
public:
    vector<int> intersection(vector<vector<int>> &a) {
        vector<int> rows(1001);
        for (int i = 0; i < a.size(); i++)
            for (int value : a[i])
                rows[value]++;
        
        vector<int> res;
        for (int value = 0; value < rows.size(); value++)
            if (rows[value] == a.size())
                res.push_back(value);
        return res;
    }
};