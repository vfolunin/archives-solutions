class Solution {
public:
    int trap(vector<int> &a) {
        int n = a.size();
        
        vector<int> prefixMax(n);
        prefixMax[0] = a[0];
        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], a[i]);
        
        vector<int> suffixMax(n);
        suffixMax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], a[i]);
        
        int res = 0;
        for (int i = 0; i < n; i++)
            res += max(0, min(prefixMax[i], suffixMax[i]) - a[i]);
        return res;
    }
};