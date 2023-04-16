class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &a) {
        int prefixMax = 0;
        vector<long long> res(a.size());

        for (int i = 0; i < a.size(); i++) {
            prefixMax = max(prefixMax, a[i]);
            res[i] = a[i] + prefixMax;
        }

        partial_sum(res.begin(), res.end(), res.begin());

        return res;
    }
};