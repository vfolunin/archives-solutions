class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
            pairs[i] = { efficiency[i], speed[i] };
        sort(pairs.begin(), pairs.end());
        
        long long sum = 0, res = 0;
        multiset<int> speeds;
        
        for (int i = n - 1; i >= 0; i--) {
            if (speeds.size() >= k) {
                sum -= *speeds.begin();
                speeds.erase(speeds.begin());
            }
            
            res = max(res, pairs[i].first * (sum + pairs[i].second));
            
            sum += pairs[i].second;
            speeds.insert(pairs[i].second);
        }
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};