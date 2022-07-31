class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &p, int aSize, int bSize) {
        partial_sum(p.begin(), p.end(), p.begin());
        int res = 0;
        
        int maxASize = p[aSize - 1];
        for (int bFrom = aSize; bFrom + bSize <= p.size(); bFrom++) {
            res = max(res, maxASize + p[bFrom + bSize - 1] - p[bFrom - 1]);
            maxASize = max(maxASize, p[bFrom] - p[bFrom - aSize]);
        }
        
        int maxBSize = p[bSize - 1];
        for (int aFrom = bSize; aFrom + aSize <= p.size(); aFrom++) {
            res = max(res, p[aFrom + aSize - 1] - p[aFrom - 1] + maxBSize);
            maxBSize = max(maxBSize, p[aFrom] - p[aFrom - bSize]);
        }
        
        return res;
    }
};