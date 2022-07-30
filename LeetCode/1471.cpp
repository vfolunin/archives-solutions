class Solution {
public:
    vector<int> getStrongest(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        
        vector<int> res;
        
        int l = 0, m = (a.size() - 1) / 2, r = a.size() - 1;
        while (res.size() < k) {
            if (abs(a[l] - a[m]) > abs(a[r] - a[m]))
                res.push_back(a[l++]);
            else
                res.push_back(a[r--]);
        }
        
        return res;
    }
};