class Solution {
public:
    int numRescueBoats(vector<int> &a, int limit) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int l = 0, r = a.size() - 1; l <= r; r--) {
            if (a[l] + a[r] <= limit)
                l++;
            res++;
        }
        
        return res;
    }
};