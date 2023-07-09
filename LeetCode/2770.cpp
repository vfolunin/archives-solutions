class Solution {
public:
    int maximumJumps(vector<int> &a, int limit) {
        vector<int> res(a.size(), -1);
        res.back() = 0;
        
        for (int i = a.size() - 1; i >= 0; i--)
            for (int j = i + 1; j < a.size(); j++)
                if (res[j] != -1 && abs(a[j] - a[i]) <= limit)
                    res[i] = max(res[i], 1 + res[j]);
        
        return res[0];
    }
};