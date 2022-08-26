class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);
        
        vector<bool> res(queries.size());
        
        for (int i = 0; i < res.size(); i++) {
            int oddCount = 0;
            for (vector<int> &p : pos) {
                auto lIt = lower_bound(p.begin(), p.end(), queries[i][0]);
                auto rIt = upper_bound(p.begin(), p.end(), queries[i][1]);
                oddCount += (rIt - lIt) % 2;
            }
            res[i] = oddCount <= queries[i][2] * 2 + 1;
        }
        
        return res;
    }
};