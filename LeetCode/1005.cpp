class Solution {
public:
    int largestSumAfterKNegations(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        
        for (int i = 0; i < a.size() && a[i] < 0 && k > 0; i++, k--)
            a[i] *= -1;
        
        if (k % 2)
            *min_element(a.begin(), a.end()) *= -1;
        
        int res = 0;
        for (int value : a)
            res += value;
        return res;
    }
};