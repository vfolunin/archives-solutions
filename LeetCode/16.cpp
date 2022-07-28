class Solution {
public:
    int threeSumClosest(vector<int> &a, int target) {
        sort(a.begin(), a.end());
        
        int res = a[0] + a[1] + a[2];
        
        for (int i = 0; i < a.size(); i++) {
            for (int l = i + 1, r = a.size() - 1; l < r; ) {
                int cur = a[i] + a[l] + a[r];
                if (abs(res - target) > abs(cur - target))
                    res = cur;
                if (cur < target)
                    l++;
                else
                    r--;
            }            
        }
        
        return res;
    }
};