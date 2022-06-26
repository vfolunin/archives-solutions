class Solution {
public:
    int partitionArray(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int l = 0, r = 0; r < a.size(); ) {
            while (r < a.size() && a[l] + k >= a[r])
                r++;
            
            res++;
            l = r;
        }
        
        return res;
    }
};