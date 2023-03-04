class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }
    
public:
    int countWays(vector<vector<int>> &a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> segments;
        for (vector<int> &segment : a) {
            if (!segments.empty() && segments.back()[1] >= segment[0])
                segments.back()[1] = max(segments.back()[1], segment[1]);
            else
                segments.push_back(segment);
        }
        
        const long long MOD = 1e9 + 7;
        return binPow(2, segments.size(), MOD);
    }
};