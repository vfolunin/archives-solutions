class Solution {
public:
    int sumOfBeauties(vector<int> &a) {
        vector<int> prefixMax = a;
        for (int i = 1; i < a.size(); i++)
            prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
        
        vector<int> suffixMin = a;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            suffixMin[i] = min(suffixMin[i], suffixMin[i + 1]);
        
        int res = 0;
        for (int i = 1; i + 1 < a.size(); i++) {
            if (prefixMax[i - 1] < a[i] && a[i] < suffixMin[i + 1])
                res += 2;
            else if (a[i - 1] < a[i] && a[i] < a[i + 1])
                res++;
        }
        return res;
    }
};