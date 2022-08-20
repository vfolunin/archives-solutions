class Solution {
public:
    vector<int> findClosestElements(vector<int> &a, int k, int x) {
        int r = lower_bound(a.begin(), a.end(), x) - a.begin(), l = r - 1;
        vector<int> res;
        
        while (res.size() < k) {
            if (r == a.size() || 0 <= l && x - a[l] <= a[r] - x)
                res.push_back(a[l--]);
            else
                res.push_back(a[r++]);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};