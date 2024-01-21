class Solution {
public:
    int minimumCost(vector<int> &a) {
        int res = 1e9;
        for (int i = 1; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res = min(res, a[0] + a[i] + a[j]);
        return res;
    }
};