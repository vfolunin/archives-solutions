class Solution {
public:
    vector<int> minCosts(vector<int> &a) {
        vector<int> res = a;
        for (int i = 1; i < res.size(); i++)
            res[i] = min(res[i], res[i - 1]);
        return res;
    }
};