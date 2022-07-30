class Solution {
public:
    long long subArrayRanges(vector<int> &a) {      
        long long res = 0;
        
        for (int l = 0; l < a.size(); l++) {
            int minValue = a[l], maxValue = a[l];
            for (int r = l; r < a.size(); r++) {
                minValue = min(minValue, a[r]);
                maxValue = max(maxValue, a[r]);
                res += maxValue - minValue;
            }
        }
        
        return res;
    }
};