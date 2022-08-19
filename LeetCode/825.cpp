class Solution {
public:
    int numFriendRequests(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            auto l = upper_bound(a.begin(), a.end(), a[i] / 2 + 7);
            auto r = upper_bound(a.begin(), a.end(), a[i]);
            res += max<int>(0, r - l - 1);
        }
        
        return res;
    }
};