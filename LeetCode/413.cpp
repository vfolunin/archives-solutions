class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &a) {
        int res = 0;
        
        for (int l = 0, r = 2; r < a.size(); l = r - 1) {
            while (r < a.size() && a[l] - a[l + 1] == a[r - 1] - a[r])
                r++;
            
            res += (r - l - 2) * (r - l - 1) / 2;
        }
        
        return res;
    }
};