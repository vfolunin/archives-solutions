class Solution {
public:
    long long maxScore(vector<int> &a, int penalty) {
        vector<long long> res(a.size(), -1e18);
        res[0] = a[0];
        
        vector<long long> last(2, -1e18);
        last[a[0] % 2] = res[0];

        for (int i = 1; i < a.size(); i++) {
            int remainder = a[i] % 2;

            if (last[remainder] != -1e18)
                res[i] = max(res[i], last[remainder] + a[i]);
            if (last[!remainder] != -1e18)
                res[i] = max(res[i], last[!remainder] + a[i] - penalty);
            
            last[remainder] = max(last[remainder], res[i]);
        }
        
        return *max_element(res.begin(), res.end());
    }
};