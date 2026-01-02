class Solution {
    long long getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    long long minimumCost(vector<int> &pa, vector<int> &pb, int factor) {
        partial_sum(pa.begin(), pa.end(), pa.begin());
        partial_sum(pb.begin(), pb.end(), pb.begin());

        vector<long long> res(pa.size(), 1e18);
        for (int r = 0; r < res.size(); r++)
            for (int l = 0; l <= r; l++)
                res[r] = min(res[r], (l ? res[l - 1] : 0) + (getSum(pa, l, r) + factor) * getSum(pb, l, res.size() - 1));        
        return res.back();
    }
};