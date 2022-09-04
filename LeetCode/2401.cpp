class Solution {
public:
    int longestNiceSubarray(vector<int> &a) {
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            int orMask = a[i], andMask = a[i], j = i + 1;
            
            for ( ; j < a.size() && !(orMask & a[j]); j++) {
                orMask |= a[j];
                andMask &= a[j];
            }
            
            res = max(res, j - i);
        }
        
        return res;
    }
};