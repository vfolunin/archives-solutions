class Solution {
public:
    int minimumCost(string &s, vector<string> &parts, vector<int> &prices) {
        vector<int> res(s.size() + 1, 1e9);
        res[0] = 0;

        for (int len = 1; len <= s.size(); len++)
            for (int i = 0; i < parts.size(); i++)
                if (parts[i].size() <= len && s.substr(len - parts[i].size(), parts[i].size()) == parts[i])
                    res[len] = min(res[len], res[len - parts[i].size()] + prices[i]);

        return res.back() < 1e9 ? res.back() : -1;
    }
};