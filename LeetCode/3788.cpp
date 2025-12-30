class Solution {
public:
    long long maximumScore(vector<int> &a) {
        vector<long long> lSum = { a.begin(), a.end() };
        partial_sum(lSum.begin(), lSum.end(), lSum.begin());

        vector<int> rMin = a;
        for (int i = (int)rMin.size() - 2; i >= 0; i--)
            rMin[i] = min(rMin[i], rMin[i + 1]);
        
        long long res = -1e18;
        for (int i = 0; i + 1 < a.size(); i++)
            res = max(res, lSum[i] - rMin[i + 1]);
        return res;
    }
};