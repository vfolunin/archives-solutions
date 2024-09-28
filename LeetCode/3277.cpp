class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int> &a, vector<vector<int>> &queries) {
        vector<vector<int>> xorScore(a.size(), vector<int>(a.size()));
        for (int i = 0; i < a.size(); i++)
            xorScore[i][i] = a[i];
        for (int len = 2; len <= a.size(); len++)
            for (int l = 0, r = len - 1; r < a.size(); l++, r++)
                xorScore[l][r] = xorScore[l + 1][r] ^ xorScore[l][r - 1];
        
        vector<vector<int>> maxXorScore(a.size(), vector<int>(a.size()));
        for (int i = 0; i < a.size(); i++)
            maxXorScore[i][i] = xorScore[i][i];
        for (int len = 2; len <= a.size(); len++)
            for (int l = 0, r = len - 1; r < a.size(); l++, r++)
                maxXorScore[l][r] = max({ xorScore[l][r], maxXorScore[l + 1][r], maxXorScore[l][r - 1] });
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = maxXorScore[queries[i][0]][queries[i][1]];
        return res;
    }
};