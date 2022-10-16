class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        vector<int> powers;
        for (int bit = 0; bit < 30; bit++)
            if (n & (1 << bit))
                powers.push_back(bit);
        
        const long long MOD = 1e9 + 7;
        vector<int> res(queries.size());
        
        for (int i = 0; i < res.size(); i++) {
            long long product = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
                product = (product * (1 << powers[j])) % MOD;
            res[i] = product;
        }
        
        return res;
    }
};