class Solution {
    string toBin(int value) {
        string res;
        while (value > 1) {
            res += value % 2 + '0';
            value /= 2;
        }
        res += value + '0';
        reverse(res.begin(), res.end());
        return res;
    }

public:
    vector<vector<int>> substringXorQueries(string &s, vector<vector<int>> &queries) {
        unordered_map<string, int> from;
        for (int i = s.size() - 1; i >= 0; i--)
            for (int len = 1; len <= 30 && i + len <= s.size(); len++)
                from[s.substr(i, len)] = i;

        vector<vector<int>> res(queries.size(), vector<int>(2, -1));
        for (int i = 0; i < queries.size(); i++) {
            string pattern = toBin(queries[i][0] ^ queries[i][1]);
            if (auto it = from.find(pattern); it != from.end())
                res[i] = { it->second, it->second + (int)pattern.size() - 1 };
        }
        return res;
    }
};