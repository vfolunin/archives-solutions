class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        
        sort(a.begin(), a.end());
        unordered_map<int, long long> ways;
        
        for (int i = 0; i < a.size(); i++) {
            ways[a[i]] = 1;
            
            for (int j = 0; 1LL * a[j] * a[j] <= a[i]; j++) {
                if (a[i] % a[j])
                    continue;
                
                int d1 = a[j], d2 = a[i] / a[j];
                if (!ways.count(d2))
                    continue;
                
                ways[a[i]] = (ways[a[i]] + ways[d1] * ways[d2] * (d1 == d2 ? 1 : 2)) % MOD;
            }
        }
        
        long long res = 0;
        for (auto &[root, ways] : ways)
            res = (res + ways) % MOD;
        return res;
    }
};