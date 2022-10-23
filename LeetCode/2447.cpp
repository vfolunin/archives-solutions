class Solution {
public:
    int subarrayGCD(vector<int> &a, int target) {
        int res = 0;
        
        for (int l = 0; l < a.size(); l++) {
            int d = 0;
            for (int r = l; r < a.size(); r++) {
                d = gcd(d, a[r]);
                res += d == target;
            }
        }
        
        return res;
    }
};