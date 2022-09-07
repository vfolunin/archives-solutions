class Solution {
    bool can(vector<int> &a, int m, int need) {
        long long count = 0;
        for (int value : a)
            if (value >= m)
                count += value - m + 1;
        return count >= need;
    }
    
    long long sum(long long from, long long to) {
        return (from + to) * (to - from + 1) / 2;
    }
    
public:
    int maxProfit(vector<int> &a, int need) {
        sort(a.rbegin(), a.rend());
        
        int l = 0, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m, need))
                l = m;
            else
                r = m;
        }
        
        cout << l << endl;
        
        long long res = 0;
        for (int value : a) {
            if (value > l) {
                need -= value - l;
                res += sum(l + 1, value);
            }
        }
        res += 1LL * need * l;
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};