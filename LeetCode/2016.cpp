class Solution {
public:
    int maximumDifference(vector<int> &a) {
        vector<int> suffixMax(a.size());
        suffixMax.back() = a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            suffixMax[i] = max(a[i], suffixMax[i + 1]);
        
        int res = -1;
        for (int i = 0; i + 1 < a.size(); i++)
            if (a[i] < suffixMax[i + 1])
                res = max(res, suffixMax[i + 1] - a[i]);
        
        return res;
    }
};