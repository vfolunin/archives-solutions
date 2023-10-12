class Solution {
public:
    long long maxScore(vector<int> &a) {
        map<int, long long> sum;
        for (int i = 0; i < a.size(); i++)
            sum[a[i] - i] += a[i];
        
        long long res = 0;
        for (auto &[shift, sum] : sum)
            res = max(res, sum);
        return res;
    }
};