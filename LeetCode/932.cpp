class Solution {
    vector<int> &rec(int n) {
        static vector<vector<int>> memo(1001);
        vector<int> &res = memo[n];
        if (!res.empty())
            return res;

        if (n == 1)
            return res = { 1 };

        for (int value : rec((n + 1) / 2))
            res.push_back(value * 2 - 1);
        for (int value : rec(n / 2))
            res.push_back(value * 2);
        return res;
    }
    
public:
    vector<int> beautifulArray(int n) {
        return rec(n);
    }
};