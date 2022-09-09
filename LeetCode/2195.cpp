class Solution {
public:
    long long minimalKSum(vector<int> &a, int k) {
        set<int> values(a.begin(), a.end());
        long long res = 1LL * k * (k + 1) / 2;
        
        for (int value : values) {
            if (value <= k) {
                res -= value;
                res += ++k;
            }
        }
        
        return res;
    }
};