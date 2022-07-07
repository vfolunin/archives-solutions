class Solution {
public:
    int sumSubarrayMins(vector<int> &a) {
        vector<int> stack, r(a.size(), a.size());
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        stack.clear();
        vector<int> l(a.size(), -1);
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] >= a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        long long res = 0, MOD = 1e9 + 7;        
        for (int i = 0; i < a.size(); i++)
            res = (res + 1LL * a[i] * (i - l[i]) * (r[i] - i)) % MOD;        
        return res;
    }
};