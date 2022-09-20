class Solution {
public:
    int maximumScore(vector<int> &a, int index) {
        vector<int> l = { a[index] };
        for (int i = index - 1; i >= 0; i--)
            l.push_back(min(l.back(), a[i]));
        
        vector<int> r = { a[index] };
        for (int i = index + 1; i < a.size(); i++)
            r.push_back(min(r.back(), a[i]));
        
        int res = 0;
        for (int value : a) {
            int lCount = upper_bound(l.begin(), l.end(), value, greater<int>()) - l.begin();
            int rCount = upper_bound(r.begin(), r.end(), value, greater<int>()) - r.begin();
            res = max(res, value * (lCount + rCount - 1));
        }
        return res;
    }
};