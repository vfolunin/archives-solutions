class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &a, vector<int> &b) {
        unordered_set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());
        
        vector<vector<int>> res(2);
        
        for (int a : sa)
            if (!sb.count(a))
                res[0].push_back(a);
        
        for (int b : sb)
            if (!sa.count(b))
                res[1].push_back(b);
        
        return res;        
    }
};