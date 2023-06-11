class Solution {
public:
    int sumDistance(vector<int> &coords, string &dirs, int moveCount) {
        vector<long long> xs = { coords.begin(), coords.end() };
        for (int i = 0; i < xs.size(); i++) {
            if (dirs[i] == 'L')
                xs[i] -= moveCount;
            else
                xs[i] += moveCount;
        }
        
        sort(xs.begin(), xs.end());
        const long long MOD = 1e9 + 7;
        long long rSum = accumulate(xs.begin(), xs.end(), 0LL), rCount = xs.size(), res = 0;
        
        for (int i = 0; i < xs.size(); i++) {
            rSum -= xs[i];
            rCount--;
            res = (res + (rSum - rCount * xs[i])) % MOD;
        }
        
        return res;
    }
};