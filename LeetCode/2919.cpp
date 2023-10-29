class Solution {
public:
    long long minIncrementOperations(vector<int> &a, int k) {
        vector<long long> res(a.size());
        
        for (int i = 0; i < 3; i++)
            res[i] = max(k - a[i], 0);

        for (int i = 3; i < a.size(); i++)
            res[i] = max(k - a[i], 0) + min({ res[i - 1], res[i - 2], res[i - 3] });

        return min({ res[a.size() - 1], res[a.size() - 2], res[a.size() - 3] });
    }
};