class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int res = 0;
        for (vector<int> &account : accounts)
            res = max(res, accumulate(account.begin(), account.end(), 0));
        return res;
    }
};