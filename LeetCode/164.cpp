class Solution {
public:
    int maximumGap(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        for (int i = 1; i < a.size(); i++)
            res = max(res, a[i] - a[i - 1]);
        return res;
    }
};