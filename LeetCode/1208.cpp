class Solution {
public:
    int equalSubstring(string &a, string &b, int limit) {
        int cost = 0, res = 0;
        
        for (int l = 0, r = 0; r < a.size(); r++) {
            cost += abs(a[r] - b[r]);
            while (cost > limit) {
                cost -= abs(a[l] - b[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};