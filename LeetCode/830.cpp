class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        
        int row = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                if (row >= 3)
                    res.push_back({ i - row, i - 1 });
                row = 1;
            }
        }
        if (row >= 3)
            res.push_back({ (int)s.size() - row, (int)s.size() - 1 });
        
        return res;
    }
};