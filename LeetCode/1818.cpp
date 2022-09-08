class Solution {
public:
    int minAbsoluteSumDiff(vector<int> &a, vector<int> &b) {
        set<int> digits(a.begin(), a.end());
        
        long long diffSum = 0;
        for (int i = 0; i < a.size(); i++)
            diffSum += abs(a[i] - b[i]);
        
        long long res = diffSum;
        for (int i = 0; i < a.size(); i++) {
            long long cur = diffSum - abs(a[i] - b[i]);
            
            auto it = digits.lower_bound(b[i]);
            if (it != digits.end())
                res = min(res, cur + abs(*it - b[i]));
            if (it != digits.begin())
                res = min(res, cur + abs(*prev(it) - b[i]));
            
            cur -= abs(a[i] - b[i]);
        }
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};