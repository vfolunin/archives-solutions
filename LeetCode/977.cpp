class Solution {
public:
    vector<int> sortedSquares(vector<int> &a) {
        vector<int> res(a.size());
        
        auto r = lower_bound(a.begin(), a.end(), 0);
        auto l = prev(r);
        
        for (int &value : res) {
            if (r == a.end() || l != prev(a.begin()) && abs(*l) < abs(*r)) {
                value = *l * *l;
                l--;
            } else {
                value = *r * *r;
                r++;
            }
        }
        
        return res;
    }
};