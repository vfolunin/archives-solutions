class Solution {
public:
    int findUnsortedSubarray(vector<int> &a) {
        int size = a.size();
        
        vector<int> rangeExtremum(size);
        rangeExtremum[0] = a[0];
        for (int i = 1; i < size; i++)
            rangeExtremum[i] = max(a[i], rangeExtremum[i - 1]);
        
        int r = size - 1;
        while (r >= 0 && rangeExtremum[r] == a[r])
            r--;
        
        if (r < 0)
            return 0;
        
        rangeExtremum[size - 1] = a[size - 1];
        for (int i = size - 2; i >= 0; i--)
            rangeExtremum[i] = min(a[i], rangeExtremum[i + 1]);
        
        int l = 0;
        while (rangeExtremum[l] == a[l])
            l++;
        
        return r - l + 1;
    }
};