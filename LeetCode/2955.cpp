class Solution {
public:
    vector<int> sameEndSubstringCount(string &s, vector<vector<int>> &queries) {
        vector<vector<int>> p(s.size(), vector<int>(26));
        for (int i = 0; i < s.size(); i++)
            for (int c = 0; c < 26; c++)
                p[i][c] = (s[i] == c + 'a') + (i ? p[i - 1][c] : 0);
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            for (int c = 0; c < 26; c++) {
                int count = p[queries[i][1]][c] - (queries[i][0] ? p[queries[i][0] - 1][c] : 0);
                res[i] += count * (count + 1) / 2;
            }
        }
        return res;
    }
};