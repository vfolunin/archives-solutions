class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int maxSumMinProduct(vector<int> &a) {
        vector<int> l(a.size(), -1), stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<int> r(a.size(), a.size());
        stack.clear();
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<long long> p = { a.begin(), a.end() };
        partial_sum(p.begin(), p.end(), p.begin());

        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, a[i] * getSum(p, l[i] + 1, r[i] - 1));
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};