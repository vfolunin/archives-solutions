class Solution {
public:
    long long minSumSquareDiff(vector<int> &a, vector<int> &b, int aOps, int bOps) {
        map<int, int> diffs;
        for (int i = 0; i < a.size(); i++)
            diffs[abs(a[i] - b[i])]++;
        
        int ops = aOps + bOps;
        while (ops) {
            auto [diff, count] = *--diffs.end();
            
            if (!diff)
                return 0;
            
            if (ops >= count) {
                diffs.erase(diff);
                diffs[diff - 1] += count;
                ops -= count;
            } else {
                diffs[diff] -= ops;
                diffs[diff - 1] += ops;
                ops = 0;
            }
        }
        
        long long res = 0;
        for (auto &[diff, count] : diffs)
            res += 1LL * diff * diff * count;
        
        return res;
    }
};